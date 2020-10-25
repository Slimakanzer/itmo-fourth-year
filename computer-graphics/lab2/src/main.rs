#[macro_use]
extern crate memoffset;

mod camera;
mod common;
mod light;
mod mesh;
mod shader;
mod snow;
mod sphere;

extern crate glfw;
use self::glfw::Context;

extern crate gl;

use camera::Camera;
use common::process_input;
use light::Light;
use shader::Shader;
use snow::Snow;
use sphere::Sphere;

use cgmath::Vector3;
use cgmath::{perspective, vec3, Deg, Matrix4, Point3};
use std::ffi::CString;

const SCR_WIDTH: u32 = 800;
const SCR_HEIGHT: u32 = 600;

fn main() {
    let mut glfw = glfw::init(glfw::FAIL_ON_ERRORS).unwrap();
    glfw.window_hint(glfw::WindowHint::ContextVersion(3, 3));
    glfw.window_hint(glfw::WindowHint::OpenGlProfile(
        glfw::OpenGlProfileHint::Core,
    ));
    glfw.window_hint(glfw::WindowHint::OpenGlForwardCompat(true));

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

    let (shader, sphere, light) = unsafe {
        gl::Enable(gl::DEPTH_TEST);

        let shader = Shader::new("src/shader/shader.vert", "src/shader/shader.frag");
        let sphere = Sphere::new(5.0, 223, 224);
        let light = Light {
            position: Vector3 {
                x: 1.2,
                y: 1.0,
                z: 5.0,
            },
            ambient: Vector3 {
                x: 0.2,
                y: 0.2,
                z: 0.2,
            },
            diffuse: Vector3 {
                x: 0.5,
                y: 0.5,
                z: 0.5,
            },
            specular: Vector3 {
                x: 0.4,
                y: 0.4,
                z: 0.4,
            },
        };
        (shader, sphere, light)
    };

    let (shader_snow, snow) = unsafe {
        gl::Enable(gl::DEPTH_TEST);
        gl::DepthFunc(gl::LEQUAL);

        let shader_snow = Shader::new("src/shader/snow.vert", "src/shader/snow.frag");
        let snow = Snow::new();

        (shader_snow, snow)
    };

    let mut camera = Camera {
        position: Point3::new(0.0, 0.0, 3.0),
        ..Camera::default()
    };

    let mut delta_time: f32; // time between current frame and last frame
    let mut last_frame: f32 = 0.0;

    while !window.should_close() {
        let current_frame = glfw.get_time() as f32;
        delta_time = current_frame - last_frame;
        last_frame = current_frame;
        process_input(&mut window, delta_time, &mut camera);

        unsafe {
            gl::ClearColor(0.1, 0.1, 0.1, 1.0);
            gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT);

            shader.use_program();

            // view/projection transformations
            let projection: Matrix4<f32> = perspective(
                Deg(camera.zoom),
                SCR_WIDTH as f32 / SCR_HEIGHT as f32,
                0.1,
                100.0,
            );
            light.setup(&shader);
            shader.set_vec3(
                &CString::new("viewPos").unwrap(),
                &Vector3 {
                    x: camera.position.x,
                    y: camera.position.y,
                    z: camera.position.z,
                },
            );

            let view = camera.get_view_matrix();
            shader.set_mat4(&CString::new("projection").unwrap(), &projection);
            shader.set_mat4(&CString::new("view").unwrap(), &view);

            // render the loaded model
            let model = Matrix4::<f32>::from_translation(vec3(0.0, -1.75, 0.0));
            shader.set_mat4(&CString::new("model").unwrap(), &model);
            sphere.draw(&shader);

            shader_snow.use_program();
            snow.draw(
                &shader_snow,
                current_frame,
                SCR_WIDTH as f32,
                SCR_HEIGHT as f32,
            );
        }

        window.swap_buffers();
        glfw.poll_events();
    }
}
