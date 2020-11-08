#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform sampler2D texture_diffuse1;

void main()
{
    vec3 ambient = texture(texture_diffuse1, TexCoords).rgb;

    vec3 result = ambient;
    FragColor = vec4(result * 1.6, 1.0);
}