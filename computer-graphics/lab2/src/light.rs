use cgmath::prelude::*;
use cgmath::Vector3;
use std::ffi::CString;

use crate::Shader;

#[repr(C)]
pub struct Light {
    pub position: Vector3<f32>,
    pub ambient: Vector3<f32>,
    pub diffuse: Vector3<f32>,
    pub specular: Vector3<f32>,
}

impl Default for Light {
    fn default() -> Self {
        Light {
            position: Vector3::zero(),
            ambient: Vector3 {
                x: 1.0,
                y: 1.0,
                z: 1.0,
            },
            diffuse: Vector3 {
                x: 1.0,
                y: 1.0,
                z: 1.0,
            },
            specular: Vector3 {
                x: 1.0,
                y: 1.0,
                z: 1.0,
            },
        }
    }
}

impl Light {
    pub fn setup(&self, shader: &Shader) {
        unsafe {
            shader.set_vec3(&CString::new("light.position").unwrap(), &self.position);
            shader.set_vec3(&CString::new("light.ambient").unwrap(), &self.ambient);
            shader.set_vec3(&CString::new("light.diffuse").unwrap(), &self.diffuse);
            shader.set_vec3(&CString::new("light.specular").unwrap(), &self.specular);
        }
    }
}
