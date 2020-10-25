#version 330 core
layout (location = 0) in vec2 aPos;

out vec2 FragCoord;

void main()
{
    FragCoord = aPos;
    gl_Position = vec4(aPos, 1.0, 1.0);
}