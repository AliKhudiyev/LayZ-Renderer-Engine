#version 330 core

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec4 vertex_color;
layout(location = 2) in vec2 texture_position;
layout(location = 3) in float texture_slot;

uniform mat4 projection = mat4(1.0);
uniform mat4 view = mat4(1.0);
uniform mat4 model = mat4(1.0);

out struct Data {
	vec4 color;
	vec2 texCoord;
	float texSlot;
} data;

void main() {

	gl_Position = projection * view * model * vec4(vertex_position.xyz, 1.0);

	data.color = vertex_color;
	data.texCoord = texture_position;
	data.texSlot = texture_slot;

}