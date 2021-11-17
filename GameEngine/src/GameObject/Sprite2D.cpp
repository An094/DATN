#include "Sprite2D.h"
#include "ResourceManager.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"

extern GLint widthScreen;
extern GLint heightScreen;
//int width = 800;
//int height = 800;

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

void Sprite2D::SetPosition(int xpos, int ypos)
{
	glm::vec2 temp;
	temp.x = (xpos - widthScreen * 0.5f) * 2.0f / widthScreen;
	temp.y = (ypos - widthScreen * 0.5f) * 2.0f / widthScreen;
	m_TransMatrix = glm::translate(m_TransMatrix, glm::vec3(temp.x, temp.y, 0.0f));
}

void Sprite2D::SetSize(int width, int height)
{
	glm::vec2 temp;
	temp.x = width * 1.0f / widthScreen;
	temp.y = height * 1.0f / heightScreen;
	m_ScaleMatrix = glm::scale(m_ScaleMatrix, glm::vec3(temp.x, temp.y, 0.0f));
}