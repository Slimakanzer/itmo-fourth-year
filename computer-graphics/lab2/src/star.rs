#![allow(non_snake_case)]

use cgmath::{Vector2, Vector3};
use gl;
use rand::Rng;
use std::ffi::CString;
use std::mem::size_of;
use std::os::raw::c_void;

use crate::Shader;
use std::ptr;

#[repr(C)]
struct Star {
    position: Vector3<f32>,
    brightness: f32,
}

pub struct Stars {
    pub VAO: u32,
    pub VBO: u32,
    stars: Vec<Star>,
    offset: Vector2<f32>,
}

pub struct Nebula {
    pub VAO: u32,
    pub VBO: u32,
    points: Vec<Vector2<f32>>,
}

pub struct SpaceBackground {
    pub stars: Stars,
    pub nebula: Nebula,
}

impl Stars {
    pub unsafe fn draw(&mut self, stars_shader: &Shader, dt: f32) {
        if self.offset.x > 10.0 || self.offset.y > 10.0 {
            self.offset.x = -5.0;
            self.offset.y = -5.0;
        }

        self.offset.x += dt * (0.03 - dt);
        self.offset.y += dt * (0.006 - dt);

        stars_shader.set_vec2(&CString::new("offset").unwrap(), &self.offset);

        // draw mesh
        gl::BindVertexArray(self.VAO);
        gl::DrawArrays(gl::POINTS, 0, self.stars.len() as i32);
        gl::BindVertexArray(0);
    }
}

impl Nebula {
    pub unsafe fn draw(&mut self, nebula_shader: &Shader, time: f32, resolution: &Vector2<f32>) {
        nebula_shader.use_program();
        nebula_shader.set_vec2(&CString::new("resolution").unwrap(), &resolution);
        nebula_shader.set_float(&CString::new("time").unwrap(), time);
        gl::BindVertexArray(self.VAO);
        gl::DrawArrays(gl::TRIANGLES, 0, self.points.len() as i32);
        gl::BindVertexArray(0);
    }
}

impl SpaceBackground {
    pub fn new(height: u32, width: u32) -> SpaceBackground {
        let stars = create_stars(width, height, 0.05);
        let nebula = create_nebula();

        SpaceBackground {
            stars: stars,
            nebula: nebula,
        }
    }

    pub unsafe fn draw(
        &mut self,
        stars_shader: &Shader,
        nebula_shader: &Shader,
        dt: f32,
        time: f32,
        resolution: &Vector2<f32>,
    ) {
        nebula_shader.use_program();
        self.nebula.draw(&nebula_shader, time, resolution);

        stars_shader.use_program();
        self.stars.draw(stars_shader, dt);
    }
}

fn create_stars(height: u32, width: u32, density: f32) -> Stars {
    let count = (height as f32 * width as f32 * density).round() as u32;

    let mut rng = rand::thread_rng();
    let mut stars = Vec::new();

    let mut i = 0;
    while i < count {
        let x = rng.gen::<f32>() * 10.0 - 5.0;
        let y = rng.gen::<f32>() * 10.0 - 5.0;
        let z = rng.gen::<f32>();
        let brightness = rng.gen::<f32>();

        stars.push(Star {
            position: Vector3 { x: x, y: y, z: z },
            brightness: brightness,
        });

        i = i + 1;
    }

    let (VAO, VBO) = unsafe {
        let (mut VBO, mut VAO) = (0, 0);

        gl::GenVertexArrays(1, &mut VAO);
        gl::GenBuffers(1, &mut VBO);

        gl::BindVertexArray(VAO);
        gl::BindBuffer(gl::ARRAY_BUFFER, VBO);

        let size = (stars.len() * size_of::<Star>()) as isize;
        let data = &stars[0] as *const Star as *const c_void;
        gl::BufferData(gl::ARRAY_BUFFER, size, data, gl::STATIC_DRAW);

        let size = size_of::<Star>() as i32;
        // vertex Positions
        gl::EnableVertexAttribArray(0);
        gl::VertexAttribPointer(
            0,
            3,
            gl::FLOAT,
            gl::FALSE,
            size,
            offset_of!(Star, position) as *const c_void,
        );

        // brightness
        gl::EnableVertexAttribArray(1);
        gl::VertexAttribPointer(
            1,
            1,
            gl::FLOAT,
            gl::FALSE,
            size,
            offset_of!(Star, brightness) as *const c_void,
        );
        gl::BindVertexArray(0);

        (VAO, VBO)
    };

    Stars {
        VAO: VAO,
        VBO: VBO,
        stars: stars,
        offset: Vector2 { x: 0.0, y: 0.0 },
    }
}

fn create_nebula() -> Nebula {
    let mut points = Vec::new();
    points.push(Vector2 { x: -1.0, y: 1.0 });
    points.push(Vector2 { x: 1.0, y: 1.0 });
    points.push(Vector2 { x: 1.0, y: -1.0 });

    points.push(Vector2 { x: 1.0, y: -1.0 });
    points.push(Vector2 { x: -1.0, y: 1.0 });
    points.push(Vector2 { x: -1.0, y: -1.0 });

    let (VAO, VBO) = unsafe {
        let (mut VBO, mut VAO) = (0, 0);

        gl::GenVertexArrays(1, &mut VAO);
        gl::GenBuffers(1, &mut VBO);

        gl::BindVertexArray(VAO);
        gl::BindBuffer(gl::ARRAY_BUFFER, VBO);

        let size = (points.len() * size_of::<Vector2<f32>>()) as isize;
        let data = &points[0] as *const Vector2<f32> as *const c_void;
        gl::BufferData(gl::ARRAY_BUFFER, size, data, gl::STATIC_DRAW);

        let size = size_of::<Vector2<f32>>() as i32;
        // vertex Positions
        gl::EnableVertexAttribArray(0);
        gl::VertexAttribPointer(0, 2, gl::FLOAT, gl::FALSE, size, ptr::null());
        gl::BindVertexArray(0);

        (VAO, VBO)
    };

    Nebula {
        VAO: VAO,
        VBO: VBO,
        points: points,
    }
}
