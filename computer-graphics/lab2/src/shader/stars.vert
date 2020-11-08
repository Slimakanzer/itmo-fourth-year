#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in float aBrightness;
uniform vec2 offset;

out float brightness;

void main()
{
    brightness = aBrightness;
    vec2 offset_pos = offset;
    if (aPos.z < 0.1) {
        offset_pos = -offset_pos;
    }
    gl_Position = vec4(aPos.xy + offset_pos * aPos.z, 1.0, 1.0);
}