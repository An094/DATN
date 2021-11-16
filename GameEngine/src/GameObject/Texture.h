#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include<glad/glad.h>
#include"GameObject/stb_image.h"

#include"shaderClass.h"

class Texture
{
public:
	GLuint ID;
	GLenum type;
	Texture(const char* image);

	// Assigns a texture unit to a texture
	void texUnit(std::shared_ptr<Shader> shader, const char* uniform, GLuint unit);
	// Binds a texture
	void Bind(GLuint slot);
	// Unbinds a texture
	void Unbind();
	// Deletes a texture
	void Delete();
};
#endif