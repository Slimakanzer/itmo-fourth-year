#version 330 core
out vec4 FragColor;

uniform vec2 resolution;
uniform float time;

// Pseudo-rand
float rand(vec2 v) {
    return fract(sin(dot(v.xy, vec2(9.918,78.233)))*33258.5453123);
}

// Perlin noise
float noise(vec2 v) {
    vec2 i = floor(v);
    vec2 f = fract(v);

    float a = rand(i);
    float b = rand(i + vec2(1.0, 0.0));
    float c = rand(i + vec2(0.0, 1.0));
    float d = rand(i + vec2(1.0, 1.0));

    // best Perlin function ever
    vec2 u = f * f * f * (f*(f*6.0 - 15.0) + 10.0);

    return mix(a, b, u.x) +
            (c - a)* u.y * (1.0 - u.x) +
            (d - b) * u.x * u.y;
}

#define NUM_OCTAVES 5

float fbm(vec2 _st) {
    float v = 0.0;
    float a = 0.5;
    vec2 shift = vec2(100.0);

    mat2 rot = mat2(cos(0.5), sin(0.5), -sin(0.5), cos(0.50));
    for (int i = 0; i < NUM_OCTAVES; ++i) {
        v += a * noise(_st);
        _st = rot * _st * 2.0 + shift;
        a *= 0.5;
    }
    return v;
}

void main() {
    vec2 st = gl_FragCoord.xy / resolution.xy * 3.0;
    float scale_time = time * 0.05;

    st += st * abs(sin(scale_time*0.1)*3.0);
    vec3 color = vec3(0.0);

    vec2 q = vec2(0.0);
    q.x = fbm(st + 0.00*scale_time);
    q.y = fbm(st + vec2(1.0));

    vec2 r = vec2(0.);
    r.x = fbm(st + 1.0*q + vec2(1.7,9.2)+ 0.15*scale_time );
    r.y = fbm(st + 1.0*q + vec2(8.3,2.8)+ 0.126*scale_time);

    float f = fbm(st+r);

    color = mix(vec3(0.101961,0.619608,0.666667),
                vec3(0.666667,0.666667,0.498039),
                clamp((f*f)*4.0,0.0,1.0));

    color = mix(color,
                vec3(0,0,0.164706),
                clamp(length(q),0.0,1.0));

    color = mix(color,
                vec3(0.666667,1,1),
                clamp(length(r.x),0.0,1.0));

    FragColor = vec4((f*f*f+.6*f*f+.5*f)*color*0.3,0.3);
}