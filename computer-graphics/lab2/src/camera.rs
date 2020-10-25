use cgmath;
use cgmath::prelude::*;
use cgmath::vec3;

type Point3 = cgmath::Point3<f32>;
type Vector3 = cgmath::Vector3<f32>;
type Matrix4 = cgmath::Matrix4<f32>;

#[derive(PartialEq, Clone, Copy)]
pub enum CameraMovement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP_ROTATION,
    DOWN_ROTATION,
    LEFT_ROTATION,
    RIGHT_ROTATION,
}
use self::CameraMovement::*;

// Default camera values
const YAW: f32 = -90.0;
const PITCH: f32 = 0.0;
const SPEED: f32 = 2.5;
const SENSITIVTY: f32 = 0.1;
const ZOOM: f32 = 45.0;

pub struct Camera {
    // Camera Attributes
    pub position: Point3,
    pub front: Vector3,
    pub up: Vector3,
    pub right: Vector3,
    pub world_up: Vector3,
    // Euler Angles
    pub yaw: f32,
    pub pitch: f32,
    // Camera options
    pub movement_speed: f32,
    pub mouse_sensitivity: f32,
    pub zoom: f32,
}

impl Default for Camera {
    fn default() -> Camera {
        let mut camera = Camera {
            position: Point3::new(0.0, 0.0, 0.0),
            front: vec3(0.0, 0.0, -1.0),
            up: Vector3::zero(),    // initialized later
            right: Vector3::zero(), // initialized later
            world_up: Vector3::unit_y(),
            yaw: YAW,
            pitch: PITCH,
            movement_speed: SPEED,
            mouse_sensitivity: SENSITIVTY,
            zoom: ZOOM,
        };
        camera.update_camera();
        camera
    }
}

impl Camera {
    pub fn get_view_matrix(&self) -> Matrix4 {
        Matrix4::look_at(self.position, self.position + self.front, self.up)
    }

    pub fn process_keyboard(&mut self, direction: CameraMovement, delta_time: f32) {
        let velocity = self.movement_speed * delta_time;
        let rotation_velocity = velocity * 20.0;
        if direction == FORWARD {
            self.position += self.front * velocity;
        }
        if direction == BACKWARD {
            self.position += -(self.front * velocity);
        }
        if direction == LEFT {
            self.position += -(self.right * velocity);
        }
        if direction == RIGHT {
            self.position += self.right * velocity;
        }
        if direction == UP_ROTATION {
            self.pitch += rotation_velocity;
            self.update_camera();
        }
        if direction == DOWN_ROTATION {
            self.pitch -= rotation_velocity;
            self.update_camera();
        }
        if direction == RIGHT_ROTATION {
            self.yaw += rotation_velocity;
            self.update_camera();
        }
        if direction == LEFT_ROTATION {
            self.yaw -= rotation_velocity;
            self.update_camera();
        }
    }

    fn update_camera(&mut self) {
        let front = Vector3 {
            x: self.yaw.to_radians().cos() * self.pitch.to_radians().cos(),
            y: self.pitch.to_radians().sin(),
            z: self.yaw.to_radians().sin() * self.pitch.to_radians().cos(),
        };
        self.front = front.normalize();

        self.right = self.front.cross(self.world_up).normalize();
        self.up = self.right.cross(self.front).normalize();
    }
}
