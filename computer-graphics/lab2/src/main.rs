#[macro_use]
extern crate memoffset;

mod camera;
mod common;
mod light;
mod mesh;
mod model;
mod shader;
mod sphere;
mod star;

extern crate glfw;
use self::glfw::Context;

extern crate gl;

use camera::Camera;
use common::{load_file_texture, process_input};
use light::Light;
use mesh::TextureType;
use model::Model;
use shader::Shader;
use sphere::Sphere;
use star::SpaceBackground;

use cgmath::{perspective, vec2, vec3, Deg, Matrix4, Point3, Rad, Vector3};
use std::ffi::CString;
const SCR_WIDTH: u32 = 1920;
const SCR_HEIGHT: u32 = 1080;

fn main() {
    let mut glfw = glfw::init(glfw::FAIL_ON_ERRORS).unwrap();
    glfw.window_hint(glfw::WindowHint::ContextVersion(3, 3));
    glfw.window_hint(glfw::WindowHint::OpenGlProfile(
        glfw::OpenGlProfileHint::Core,
    ));
    glfw.window_hint(glfw::WindowHint::OpenGlForwardCompat(true));

    let resolution = vec2(SCR_WIDTH as f32, SCR_HEIGHT as f32);
    let (mut window, _events) = glfw
        .create_window(
            SCR_WIDTH,
            SCR_HEIGHT,
            "LearnOpenGL",
            glfw::WindowMode::Windowed,
        )
        .expect("Failed to create GLFW window");

    window.make_current();
    window.set_key_polling(true);
    window.set_framebuffer_size_polling(true);

    gl::load_with(|symbol| window.get_proc_address(symbol) as *const _);

    let (shader_stars, nebula_shader, mut background) = unsafe {
        gl::Enable(gl::DEPTH_TEST);
        gl::DepthFunc(gl::LEQUAL);
        let shader_stars = Shader::new("src/shader/stars.vert", "src/shader/stars.frag");
        let shader_nebula = Shader::new("src/shader/nebula.vert", "src/shader/nebula.frag");
        let background = SpaceBackground::new(SCR_HEIGHT, SCR_WIDTH);

        (shader_stars, shader_nebula, background)
    };
    let (sun_shader, planet_shader, sun, planet) = unsafe {
        gl::Enable(gl::DEPTH_TEST);
        let sun_shader = Shader::new("src/shader/sun.vert", "src/shader/sun.frag");
        let mut sun_textures = Vec::new();
        sun_textures.push(load_file_texture(
            "resources/sun_texture.bmp",
            TextureType::Diffuse,
        ));
        let sun = Sphere::new(1.0, 50, 50, sun_textures);

        let planet_shader = Shader::new("src/shader/planet.vert", "src/shader/planet.frag");
        let mut planet_textures = Vec::new();
        planet_textures.push(load_file_texture(
            "resources/earth_texture.bmp",
            TextureType::Diffuse,
        ));
        planet_textures.push(load_file_texture(
            "resources/earth_specular.bmp",
            TextureType::Specular,
        ));
        let planet = Sphere::new(0.1, 50, 50, planet_textures);

        (sun_shader, planet_shader, sun, planet)
    };
    let object = Model::new("resources/rock/rock.obj");
    let light = Light::default();
    let mut camera = Camera {
        position: Point3::new(0.0, 1.0, 10.0),
        ..Camera::default()
    };

    let mut dt: f32; // time between current frame and last frame
    let mut last_frame: f32 = 0.0;
    let mut x = 0.0;
    let mut z = 0.0;

    while !window.should_close() {
        let current_frame = glfw.get_time() as f32;
        dt = current_frame - last_frame;
        last_frame = current_frame;
        x = (current_frame / 10.0).sin() * 5.0;
        z = (current_frame / 10.0).cos() * 5.0;
        process_input(&mut window, dt, &mut camera);

        unsafe {
            gl::ClearColor(0.0, 0.0, 0.0, 1.0);
            gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT);

            background.draw(
                &shader_stars,
                &nebula_shader,
                dt,
                current_frame,
                &resolution,
            );

            let model = Matrix4::<f32>::from_translation(vec3(0.0, 0.0, 0.0));
            let view = camera.get_view_matrix();
            let projection: Matrix4<f32> = perspective(
                Deg(camera.zoom),
                SCR_WIDTH as f32 / SCR_HEIGHT as f32,
                0.1,
                100.0,
            );

            sun_shader.use_program();
            sun_shader.set_mat4(&CString::new("model").unwrap(), &model);
            sun_shader.set_mat4(&CString::new("view").unwrap(), &view);
            sun_shader.set_mat4(&CString::new("projection").unwrap(), &projection);
            sun.draw(&sun_shader);

            let model = Matrix4::<f32>::from_translation(vec3(x, 0.0, z))
                * Matrix4::<f32>::from_angle_y(Rad(current_frame));
            planet_shader.use_program();
            planet_shader.set_mat4(&CString::new("model").unwrap(), &model);
            planet_shader.set_mat4(&CString::new("view").unwrap(), &view);
            planet_shader.set_mat4(&CString::new("projection").unwrap(), &projection);
            planet_shader.set_vec3(
                &CString::new("viewPos").unwrap(),
                &Vector3 {
                    x: camera.position.x,
                    y: camera.position.y,
                    z: camera.position.z,
                },
            );
            light.setup(&planet_shader);
            planet.draw(&planet_shader);

            let model = Matrix4::<f32>::from_translation(vec3(-10.0, 0.0, -10.0))
                * Matrix4::<f32>::from_angle_x(Rad(current_frame / 50.0))
                * Matrix4::<f32>::from_angle_y(Rad(current_frame / 50.0));
            planet_shader.set_mat4(&CString::new("model").unwrap(), &model);
            object.draw(&planet_shader);
        }

        window.swap_buffers();
        glfw.poll_events();
    }
}
