#version 330 core

uniform sampler2D textures[32];

in struct Data {
	vec4 color;
	vec2 texCoord;
	float texSlot;
} data;

out vec4 Color;

void main() {

	Color = data.color;

	if (data.texSlot > -0.5) {
		Color = texture(textures[int(data.texSlot + 0.1)], data.texCoord);
		// Color = vec4(int(data.texSlot + 0.1), int(data.texSlot + 0.1), 1.0, 1.0);
	}

}