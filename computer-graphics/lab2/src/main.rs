#[macro_use]
extern crate memoffset;

mod camera;
mod common;
mod mesh;
mod shader;
mod sphere;

extern crate glfw;
use self::glfw::Context;

extern crate gl;

use camera::Camera;
use common::{process_events, process_input};
use shader::Shader;
use sphere::Sphere;

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

    let (mut window, events) = glfw
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

    let (shader, sphere) = unsafe {
        gl::Enable(gl::DEPTH_TEST);

        let shader = Shader::new("src/shader/shader.vert", "src/shader/shader.frag");
        let sphere = Sphere::new(3.5, 223, 224);

        (shader, sphere)
    };

    let mut camera = Camera {
        position: Point3::new(0.0, 0.0, 3.0),
        ..Camera::default()
    };

    let mut first_mouse = true;
    let mut last_x: f32 = SCR_WIDTH as f32 / 2.0;
    let mut last_y: f32 = SCR_HEIGHT as f32 / 2.0;

    let mut delta_time: f32; // time between current frame and last frame
    let mut last_frame: f32 = 0.0;

    while !window.should_close() {
        let current_frame = glfw.get_time() as f32;
        delta_time = current_frame - last_frame;
        last_frame = current_frame;

        process_events(
            &events,
            &mut first_mouse,
            &mut last_x,
            &mut last_y,
            &mut camera,
        );
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
            let view = camera.get_view_matrix();
            shader.set_mat4(&CString::new("projection").unwrap(), &projection);
            shader.set_mat4(&CString::new("view").unwrap(), &view);

            // render the loaded model
            let mut model = Matrix4::<f32>::from_translation(vec3(0.0, -1.75, 0.0));
            model = model * Matrix4::from_scale(0.2);
            shader.set_mat4(&CString::new("model").unwrap(), &model);
            sphere.draw(&shader);
        }

        window.swap_buffers();
        glfw.poll_events();
    }
}
