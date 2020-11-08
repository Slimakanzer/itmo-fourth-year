use cgmath::{vec2, vec3};
use std::f32::consts::PI;
use std::vec::Vec;

use crate::mesh::{Mesh, Texture, Vertex};
use crate::Shader;

pub struct Sphere {
    pub mesh: Mesh,
}

impl Sphere {
    pub fn new(r: f32, sector_count: u32, stack_count: u32, textures: Vec<Texture>) -> Sphere {
        let mut vertices = Vec::new();
        let mut indices = Vec::new();

        let sector_step = 2.0 * PI / sector_count as f32;
        let stack_step = PI / stack_count as f32;

        let length_inv = 1.0 / r;

        let mut i = 0;
        while i <= stack_count {
            let stack_angle = PI / 2.0 - i as f32 * stack_step; // starting from pi/2 to -pi/2
            let xy = r as f32 * stack_angle.cos(); // r * cos(u)
            let z = r as f32 * stack_angle.sin(); // r * sin(u)

            let mut j = 0;
            while j <= sector_count {
                let sector_angle = j as f32 * sector_step; // starting from 0 to 2pi

                // vertex position (x, y, z)
                let x = xy * sector_angle.cos(); // r * cos(u) * cos(v)
                let y = xy * sector_angle.sin(); // r * cos(u) * sin(v)

                let nx = x * length_inv;
                let ny = y * length_inv;
                let nz = z * length_inv;

                let s = j as f32 / sector_count as f32;
                let t = i as f32 / stack_count as f32;

                vertices.push(Vertex {
                    position: vec3(x, y, z),
                    normal: vec3(nx, ny, nz),
                    tex_coords: vec2(s, t),
                    ..Vertex::default()
                });

                j = j + 1;
            }
            i = i + 1;
        }

        let mut i = 0;
        while i < stack_count {
            let mut k1 = i * (sector_count + 1);
            let mut k2 = k1 + sector_count + 1;

            let mut j: u32 = 0;
            while j < sector_count {
                if i != 0 {
                    indices.push(k1);
                    indices.push(k2);
                    indices.push(k1 + 1);
                }

                if i != (stack_count - 1) {
                    indices.push(k1 + 1);
                    indices.push(k2);
                    indices.push(k2 + 1);
                }

                k1 = k1 + 1;
                k2 = k2 + 1;
                j = j + 1;
            }
            i = i + 1;
        }

        let mesh = Mesh::new(vertices, indices, textures);
        Sphere { mesh: mesh }
    }

    pub unsafe fn draw(&self, shader: &Shader) {
        self.mesh.draw(shader);
    }
}
