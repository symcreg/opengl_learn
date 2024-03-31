#version 430 core
in vec3 color;
in vec3 pos;
out vec4 FragColor;
void main()
{
   //FragColor = vec4(color,1.0);
   FragColor = vec4(pos,1.0);
}
