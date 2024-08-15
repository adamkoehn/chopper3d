#version 300 es

precision mediump float;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 LightPosition;

out vec4 FragColor;

void main() {
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(LightPosition - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * vec3(0.5);
    FragColor = vec4(diffuse + vec3(0.5), 1.0);
}
