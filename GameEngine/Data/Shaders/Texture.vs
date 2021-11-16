#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;

uniform mat4 trans;
uniform mat4 rotate;
uniform mat4 scale;

out vec2 texCoord;

void main()
{
    gl_Position = trans * rotate * scale * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    texCoord = aTex;
}