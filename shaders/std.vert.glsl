#version 300 es

layout(location = 0) in vec3 Vertex;

void main() {
    gl_Position = vec4(Vertex, 1.0);
}
