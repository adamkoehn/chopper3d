#version 300 es

precision mediump float;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;

uniform vec3 LightPosition;
uniform sampler2D Texture;

out vec4 FragColor;

void main() {
    vec3 ambient = vec3(0.3);
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(LightPosition - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = vec3(1.0) * diff;
    FragColor = vec4(diffuse + ambient, 1.0) * texture(Texture, TexCoords);
}
