use gl;
extern crate glfw;
use self::glfw::{Action, Key};

use image;
use image::DynamicImage::*;
use image::GenericImage;
use std::os::raw::c_void;
use std::path::Path;

use crate::mesh;
use mesh::{Texture, TextureType};

use crate::camera;
use camera::Camera;
use camera::CameraMovement::*;

pub fn process_input(window: &mut glfw::Window, delta_time: f32, camera: &mut Camera) {
    if window.get_key(Key::Escape) == Action::Press {
        window.set_should_close(true)
    }

    if window.get_key(Key::W) == Action::Press {
        camera.process_keyboard(FORWARD, delta_time);
    }
    if window.get_key(Key::S) == Action::Press {
        camera.process_keyboard(BACKWARD, delta_time);
    }
    if window.get_key(Key::A) == Action::Press {
        camera.process_keyboard(LEFT, delta_time);
    }
    if window.get_key(Key::D) == Action::Press {
        camera.process_keyboard(RIGHT, delta_time);
    }

    if window.get_key(Key::Up) == Action::Press {
        camera.process_keyboard(UP_ROTATION, delta_time);
    }
    if window.get_key(Key::Down) == Action::Press {
        camera.process_keyboard(DOWN_ROTATION, delta_time);
    }
    if window.get_key(Key::Left) == Action::Press {
        camera.process_keyboard(LEFT_ROTATION, delta_time);
    }
    if window.get_key(Key::Right) == Action::Press {
        camera.process_keyboard(RIGHT_ROTATION, delta_time);
    }
}

pub fn load_texture(path: &str, texture_type: TextureType) -> Texture {
    Texture {
        id: unsafe { load_texture_from_file(path) },
        texture_type: texture_type,
        path: path.into(),
    }
}

unsafe fn load_texture_from_file(filename: &str) -> u32 {
    let mut texture_id = 0;
    gl::GenTextures(1, &mut texture_id);

    let img = image::open(&Path::new(&filename)).expect("Texture failed to load");
    let img = img.flipv();
    let format = match img {
        ImageLuma8(_) => gl::RED,
        ImageLumaA8(_) => gl::RG,
        ImageRgb8(_) => gl::RGB,
        ImageRgba8(_) => gl::RGBA,
    };

    let data = img.raw_pixels();

    gl::BindTexture(gl::TEXTURE_2D, texture_id);
    gl::TexImage2D(
        gl::TEXTURE_2D,
        0,
        format as i32,
        img.width() as i32,
        img.height() as i32,
        0,
        format,
        gl::UNSIGNED_BYTE,
        &data[0] as *const u8 as *const c_void,
    );
    gl::GenerateMipmap(gl::TEXTURE_2D);

    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_S, gl::REPEAT as i32);
    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_T, gl::REPEAT as i32);
    gl::TexParameteri(
        gl::TEXTURE_2D,
        gl::TEXTURE_MIN_FILTER,
        gl::LINEAR_MIPMAP_LINEAR as i32,
    );
    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MAG_FILTER, gl::LINEAR as i32);

    texture_id
}
