#version 330 core

in vec3 user_color;

out vec4 Color;

void main() {

	Color = vec4(user_color, 1.0);

}