#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;
layout (location = 2) in vec2 aTex;
out vec3 aCo;
out vec2 aTe;
// uniforms
uniform mat4 model;
uniform float th;

void main()
{
	gl_Position = model * vec4(aPos, 1.0);
	aTe = aTex;

	if (th == 0.2)
	{
		aCo = aCol * 0.0;
	}
	else {
		aCo = aCol;
	}
}