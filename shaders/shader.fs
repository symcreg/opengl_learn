#version 430 core
in vec3 pos;
in vec3 color;
in vec2 texCoord;
out vec4 FragColor;
uniform sampler2D myTexture;
void main()
{
//    FragColor = vec4(color,1.0);
    FragColor = texture(myTexture,texCoord);
}
