use crate::common::load_file_texture;
use crate::mesh::{Mesh, Texture, TextureType, Vertex};
use crate::Shader;
use cgmath::{vec2, vec3};
use std::path::Path;
use tobj;

#[derive(Default)]
pub struct Model {
    pub meshes: Vec<Mesh>,
    pub textures_loaded: Vec<Texture>,
}

impl Model {
    pub fn new(path: &str) -> Model {
        let mut model = Model::default();
        model.load_model(path);
        model
    }

    pub fn draw(&self, shader: &Shader) {
        for mesh in &self.meshes {
            unsafe {
                mesh.draw(&shader);
            }
        }
    }

    fn load_model(&mut self, path: &str) {
        let path = Path::new(path);
        let dir = path
            .parent()
            .unwrap_or_else(|| Path::new(""))
            .to_str()
            .unwrap()
            .into();

        let (models, materials) =
            tobj::load_obj(&Path::new(path), false).expect("Failed to load file");
        for model in models {
            let mesh = &model.mesh;
            let num_vertices = mesh.positions.len() / 3;

            let mut vertices: Vec<Vertex> = Vec::with_capacity(num_vertices);
            let indices: Vec<u32> = mesh.indices.clone();

            let (p, n, t) = (&mesh.positions, &mesh.normals, &mesh.texcoords);
            for i in 0..num_vertices {
                vertices.push(Vertex {
                    position: vec3(p[i * 3], p[i * 3 + 1], p[i * 3 + 2]),
                    normal: vec3(n[i * 3], n[i * 3 + 1], n[i * 3 + 2]),
                    tex_coords: vec2(t[i * 2], t[i * 2 + 1]),
                    ..Vertex::default()
                })
            }

            let mut textures = Vec::new();
            if let Some(material_id) = mesh.material_id {
                let material = &materials[material_id];

                if !material.diffuse_texture.is_empty() {
                    let texture = self.load_material_texture(
                        dir,
                        &material.diffuse_texture,
                        TextureType::Diffuse,
                    );
                    textures.push(texture);
                }
                if !material.specular_texture.is_empty() {
                    let texture = self.load_material_texture(
                        dir,
                        &material.specular_texture,
                        TextureType::Specular,
                    );
                    textures.push(texture);
                }
                if !material.normal_texture.is_empty() {
                    let texture = self.load_material_texture(
                        dir,
                        &material.normal_texture,
                        TextureType::Normal,
                    );
                    textures.push(texture);
                }
            }

            self.meshes.push(Mesh::new(vertices, indices, textures));
        }
    }

    fn load_material_texture(
        &mut self,
        directory: &str,
        filename: &str,
        texture_type: TextureType,
    ) -> Texture {
        let path = format!("{}/{}", directory, filename);
        {
            let texture = self.textures_loaded.iter().find(|t| t.path == path);
            if let Some(texture) = texture {
                return texture.clone();
            }
        }

        let texture = load_file_texture(&path, texture_type);
        self.textures_loaded.push(texture.clone());
        texture
    }
}
