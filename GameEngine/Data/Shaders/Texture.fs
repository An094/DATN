#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D tex0;

void main()
{
	//FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
	FragColor = texture(tex0, texCoord);
}