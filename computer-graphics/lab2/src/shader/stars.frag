#version 330 core
out vec4 FragColor;
in float brightness;

void main() {
    FragColor = vec4(brightness); // 0.0
}