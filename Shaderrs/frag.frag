#version 330 core

in vec3 aCo;
in vec2 aTe;
out vec4 Color;

uniform sampler2D ourTexture;

void main()
{
	Color = texture(ourTexture, aTe);
	// Color = vec4(aCo, 1.0);
}