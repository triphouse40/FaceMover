#version 330 core

in vec3 aCo;
out vec4 Color;

void main()
{
	Color = vec4(aCo, 1.0);
}