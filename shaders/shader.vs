#version 430 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 color;
out vec3 pos;

uniform float xOffset;
uniform float yOffset;

void main()
{
   gl_Position = vec4(aPos.x + xOffset, aPos.y + yOffset, aPos.z, 1.0);
   color = aColor;
   pos = aPos;
}
