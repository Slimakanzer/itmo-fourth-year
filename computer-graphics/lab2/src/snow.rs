use cgmath::Vector2;
use gl;
use gl::types::*;
use std::ffi::CString;
use std::mem::size_of;
use std::os::raw::c_void;
use std::ptr;

use crate::Shader;

pub struct Snow {
    VAO: u32,
    VBO: u32,
}

impl Snow {
    pub fn new() -> Snow {
        let (VAO, VBO) = unsafe {
            let (mut VBO, mut VAO) = (0, 0);

            gl::GenVertexArrays(1, &mut VAO);
            gl::GenBuffers(1, &mut VBO);

            gl::BindVertexArray(VAO);
            gl::BindBuffer(gl::ARRAY_BUFFER, VBO);

            let vertices: [f32; 12] = [
                -1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0, -1.0, -1.0,
            ];

            let size = (vertices.len() * size_of::<GLfloat>()) as isize;
            let data = &vertices[0] as *const f32 as *const c_void;
            gl::BufferData(gl::ARRAY_BUFFER, size, data, gl::STATIC_DRAW);

            // vertex Positions
            let size = 2 * size_of::<GLfloat>() as i32;
            gl::EnableVertexAttribArray(0);
            gl::VertexAttribPointer(0, 2, gl::FLOAT, gl::FALSE, size, ptr::null());
            gl::BindVertexArray(0);

            (VAO, VBO)
        };

        Snow { VAO: VAO, VBO: VBO }
    }

    pub unsafe fn draw(&self, shader: &Shader, time: f32, width: f32, height: f32) {
        shader.set_float(&CString::new("time").unwrap(), time);
        shader.set_vec2(
            &CString::new("resolution").unwrap(),
            &Vector2 {
                x: width / 300.0,
                y: height / 300.0,
            },
        );

        // draw mesh
        gl::BindVertexArray(self.VAO);
        gl::DrawArrays(gl::TRIANGLES, 0, 6);
        gl::BindVertexArray(0);
    }
}
