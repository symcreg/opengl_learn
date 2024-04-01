#version 430 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 color;
out vec2 texCoord;

uniform float xOffset;
uniform float yOffset;
uniform float zOffset;

//uniform vec3 aColor;

void main()
{
   gl_Position = vec4(aPos.x + xOffset, aPos.y + yOffset, aPos.z + zOffset, 1.0);
   color = aColor;
   texCoord = aTexCoord;
}

