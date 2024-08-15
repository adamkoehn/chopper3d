#version 300 es

layout(location = 0) in vec3 Position;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inTexCoords;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

out vec3 Normal;
out vec3 FragPos;
out vec2 TexCoords;

void main() {
    gl_Position = Projection * View * Model * vec4(Position, 1.0f);
    Normal = inNormal;
    FragPos = vec3(Model * vec4(Position, 1.0));
    TexCoords = inTexCoords;
}
