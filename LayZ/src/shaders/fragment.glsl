#version 330 core

in vec4 user_color;

out vec4 Color;

void main() {

	Color = vec4(user_color);

}