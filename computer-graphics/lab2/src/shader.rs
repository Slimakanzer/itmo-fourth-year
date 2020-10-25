use std::ffi::CString;
use std::fs;
use std::ptr;
use std::str;

use gl;
use gl::types::*;

use cgmath::{Matrix, Matrix4};

pub struct Shader {
    pub id: u32,
}

impl Shader {
    pub fn new(vertex: &str, fragment: &str) -> Shader {
        let mut shader = Shader { id: 0 };

        let vertex_content = fs::read_to_string(vertex).expect("Invalid vertext filepath");
        let fragment_content = fs::read_to_string(fragment).expect("Invalid fragment filepath");

        let v_shader_code = CString::new(vertex_content.as_bytes()).unwrap();
        let f_shader_code = CString::new(fragment_content.as_bytes()).unwrap();

        unsafe {
            let vertex = shader.compile_shader(gl::VERTEX_SHADER, &v_shader_code);
            let fragment = shader.compile_shader(gl::FRAGMENT_SHADER, &f_shader_code);

            let id = gl::CreateProgram();
            gl::AttachShader(id, vertex);
            gl::AttachShader(id, fragment);
            gl::LinkProgram(id);
            shader.check_program_link(id);

            gl::DeleteShader(vertex);
            gl::DeleteShader(fragment);
            shader.id = id;
        }

        shader
    }

    unsafe fn compile_shader(&self, type_shader: GLenum, shader_code: &CString) -> GLuint {
        let fragment = gl::CreateShader(type_shader);
        gl::ShaderSource(fragment, 1, &shader_code.as_ptr(), ptr::null());
        gl::CompileShader(fragment);
        self.check_shader_compile(fragment);

        fragment
    }

    unsafe fn check_shader_compile(&self, shader: GLuint) {
        let mut success = gl::FALSE as GLint;
        let mut info_log = Vec::with_capacity(512);

        gl::GetShaderiv(shader, gl::COMPILE_STATUS, &mut success);
        if success != gl::TRUE as GLint {
            gl::GetShaderInfoLog(
                shader,
                512,
                ptr::null_mut(),
                info_log.as_mut_ptr() as *mut GLchar,
            );
            panic!(
                "ERROR::SHADER::COMPILATION_FAILED Shader:{}\n{}",
                shader,
                str::from_utf8(&info_log).unwrap()
            );
        }
    }

    unsafe fn check_program_link(&self, program: GLuint) {
        let mut success = gl::FALSE as GLint;
        let mut info_log = Vec::with_capacity(512);

        gl::GetProgramiv(program, gl::LINK_STATUS, &mut success);
        if success != gl::TRUE as GLint {
            gl::GetProgramInfoLog(
                program,
                512,
                ptr::null_mut(),
                info_log.as_mut_ptr() as *mut GLchar,
            );
            panic!(
                "ERROR::PROGRAM::COMPILATION_FAILED Program:{}\n{}",
                program,
                str::from_utf8(&info_log).unwrap()
            );
        }
    }

    pub unsafe fn set_mat4(&self, name: &CString, mat: &Matrix4<f32>) {
        gl::UniformMatrix4fv(
            gl::GetUniformLocation(self.id, name.as_ptr()),
            1,
            gl::FALSE,
            mat.as_ptr(),
        );
    }

    pub unsafe fn use_program(&self) {
        gl::UseProgram(self.id)
    }
}
