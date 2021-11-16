#include "Sprite2D.h"
#include "ResourceManager.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"

//extern GLint width;
//extern GLint height;

Sprite2D::Sprite2D(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	:m_Model(model), m_Shader(shader), m_Texture(texture)
{
	m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_TransMatrix = glm::mat4(1.0f);
	m_RotateMatrix = glm::mat4(1.0f);
	m_ScaleMatrix = glm::mat4(1.0f);
}

Sprite2D::~Sprite2D()
{

}

void Sprite2D::Init()
{

}

void Sprite2D::Draw()
{
	//[IMPORTANT] Create VAO before Initialize data 
	// Generates Vertex Array Object and binds it
	//m_Shader->Activate();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	std::shared_ptr<VAO> vao = m_Model->getVAO();
	std::shared_ptr<VBO> vbo = m_Model->getVBO();
	std::shared_ptr<EBO> ebo = m_Model->getEBO();
	vao->Bind();
	vbo->Bind();
	ebo->Bind();

	vao->LinkAttrib(vbo, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
	vao->LinkAttrib(vbo, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));

	m_Texture->texUnit(m_Shader, "tex0", 0);
	m_Texture->Bind(0);

	GLuint transUni = glGetUniformLocation(m_Shader->ID, "trans");
	GLuint rotateUni = glGetUniformLocation(m_Shader->ID, "rotate");
	GLuint scaleUni = glGetUniformLocation(m_Shader->ID, "scale");

	glUniformMatrix4fv(transUni, 1, GL_FALSE, glm::value_ptr(m_TransMatrix));
	glUniformMatrix4fv(rotateUni, 1, GL_FALSE, glm::value_ptr(m_RotateMatrix));
	glUniformMatrix4fv(scaleUni, 1, GL_FALSE, glm::value_ptr(m_ScaleMatrix));

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	vao->Unbind();
	vbo->Unbind();
	ebo->Unbind();
}

void Sprite2D::SetPosition(glm::vec2 pos)
{
	m_Position = pos;
}

void Sprite2D::SetSize(int width, int height)
{
	return;
}