#include "SpriteAnimation2D.h"

#include "GameManager/ResourceManager.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"

//extern GLint width;
//extern GLint height;

SpriteAnimation2D::SpriteAnimation2D(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, 
	int numberFrame, float frameTime)
	: Sprite2D(model, shader, texture)
{
	m_NumberFrame = numberFrame;
	m_FrameTime = frameTime;
	m_CurrentFrame = 0;
	m_CurrentTime = 0.0f;
}

SpriteAnimation2D::SpriteAnimation2D(const std::string& modelName, const std::string& shaderName, const std::string& textureName,
	int numberFrame, float frameTime)
	:Sprite2D(modelName, shaderName, textureName)
{
	m_NumberFrame = numberFrame;
	m_FrameTime = frameTime;
	m_CurrentFrame = 0;
	m_CurrentTime = 0.0f;
}

SpriteAnimation2D::~SpriteAnimation2D()
{

}

void SpriteAnimation2D::Init()
{

}

void SpriteAnimation2D::Draw()
{
	//[IMPORTANT] Create VAO before Initialize data 
	// Generates Vertex Array Object and binds it
	//m_Shader->Activate();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	std::shared_ptr<VAO> vao = GetModel()->getVAO();
	std::shared_ptr<VBO> vbo = GetModel()->getVBO();
	std::shared_ptr<EBO> ebo = GetModel()->getEBO();
	vao->Bind();
	vbo->Bind();
	ebo->Bind();

	vao->LinkAttrib(vbo, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
	vao->LinkAttrib(vbo, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));

	GetTexture()->texUnit(GetShader(), "tex0", 0);
	GetTexture()->Bind(0);

	GLuint transUni = glGetUniformLocation(GetShader()->ID, "trans");
	GLuint rotateUni = glGetUniformLocation(GetShader()->ID, "rotate");
	GLuint scaleUni = glGetUniformLocation(GetShader()->ID, "scale");
	GLuint curFrameUni = glGetUniformLocation(GetShader()->ID, "currentFrame");
	GLuint numFrameUni = glGetUniformLocation(GetShader()->ID, "numberFrame");

	glUniformMatrix4fv(transUni, 1, GL_FALSE, glm::value_ptr(GetTransMatrix()));
	glUniformMatrix4fv(rotateUni, 1, GL_FALSE, glm::value_ptr(GetRotateMatrix()));
	glUniformMatrix4fv(scaleUni, 1, GL_FALSE, glm::value_ptr(GetScaleMatrix()));
	glUniform1f(curFrameUni, m_CurrentFrame);
	glUniform1f(numFrameUni, m_NumberFrame);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	vao->Unbind();
	vbo->Unbind();
	ebo->Unbind();
}

void SpriteAnimation2D::Update(float deltaTime)
{
	m_CurrentTime += deltaTime;
	if (m_CurrentTime >= m_FrameTime)
	{
		m_CurrentFrame++;
		if (m_CurrentFrame >= m_NumberFrame)
			m_CurrentFrame = 0;
		m_CurrentTime -= m_FrameTime;
	}
}