#include "Application.h"
#include "shaderClass.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Model.h"
#include "ResourceManager.h"
std::shared_ptr<Application> Application::s_Instance = nullptr;
Application::Application()
{

}

Application::~Application()
{

}

void Application::Init()
{
	//[IMPORTANT] Create VAO before Initialize data 
	// Generates Vertex Array Object and binds it
	m_VAO = std::make_shared<VAO>();
	m_VAO->Bind();

	//Initialize data
	ResourceManager::GetInstance()->Init();

	m_Shader = ResourceManager::GetInstance()->GetShader("Texture");
	std::shared_ptr<Model> model = ResourceManager::GetInstance()->GetModel("Texture");
	
	m_VAO->LinkAttrib(model->getVBO(), 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
	m_VAO->LinkAttrib(model->getVBO(), 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	m_VAO->Unbind();

}

void Application::Update(GLfloat deltaTime)
{
	//std::cout << "Application::Update" << std::endl;
}

void Application::Draw()
{
	//std::cout << "Application::Draw" << std::endl;
	m_Shader->Activate();
	m_VAO->Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Application::HandleKeyEvent(int key, bool isPressed)
{
	//std::cout << "Key: " << key << " isPressed: " << isPressed << std::endl;
}

void Application::HandleTouchEvent(double xpos, double ypos, bool isPressed)
{

}