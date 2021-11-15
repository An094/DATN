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
	std::cout << "Application::Init" << std::endl;
	//shader = new Shader("Data/Shaders/Texture.vs", "Data/Shaders/Texture.fs");
	//shader = new Shader("D:/DATN/Project/DoAnTotNghiep/GameEngine/Data/Shaders/Texture.vs", "D:/DATN/Project/DoAnTotNghiep/GameEngine/Data/Shaders/Texture.fs");
	m_Shader = ResourceManager::GetInstance()->GetShader("Texture");

	// Generates Vertex Array Object and binds it
	VAO1 = new VAO();
	VAO1->Bind();

	//std::shared_ptr<Model> model = std::make_shared<Model>("D:/DATN/Project/DoAnTotNghiep/GameEngine/Data/Models/Texture.txt");
	std::shared_ptr<Model> model = ResourceManager::GetInstance()->GetModel("Texture");
	VAO1->LinkAttrib(model->getVBO(), 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
	VAO1->LinkAttrib(model->getVBO(), 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1->Unbind();

}

void Application::Update(GLfloat deltaTime)
{
	std::cout << "Application::Update" << std::endl;
}

void Application::Draw()
{
	std::cout << "Application::Draw" << std::endl;
	m_Shader->Activate();
	VAO1->Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Application::HandleKeyEvent(int key, bool isPressed)
{

}

void Application::HandleTouchEvent(double xpos, double ypos, bool isPressed)
{

}