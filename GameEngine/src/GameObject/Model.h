#pragma once
#include <iostream>
#include <glad/glad.h>

class VBO;
class EBO;
class Model
{
private:
	std::shared_ptr<VBO> m_VBO;
	std::shared_ptr<EBO> m_EBO;
public:
	Model(const std::string& fileName );
	inline std::shared_ptr <VBO> getVBO() { return m_VBO; }
	inline std::shared_ptr <EBO> getEBO() { return m_EBO; }
};

