#pragma once
#include <iostream>
#include <glad/glad.h>

class VBO;
class EBO;
class Model
{
private:
	VBO* m_VBO;
	EBO* m_EBO;
public:
	Model(const std::string& fileName );
	inline VBO* getVBO() { return m_VBO; }
	inline EBO* getEBO() { return m_EBO; }
};

