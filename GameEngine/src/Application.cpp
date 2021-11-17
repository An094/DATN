#include "Application.h"
#include "shaderClass.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Model.h"
#include "Sprite2D.h"
#include "SpriteAnimation2D.h"
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
	////Initialize data
	ResourceManager::GetInstance()->Init();

	/*m_Shader = ResourceManager::GetInstance()->GetShader("Texture");
	m_Model = ResourceManager::GetInstance()->GetModel("Texture");
	m_Texture = ResourceManager::GetInstance()->GetTexture("Logo.tga");

	m_sprite2d = std::make_shared<Sprite2D>(m_Model, m_Shader, m_Texture);*/

	m_Shader = ResourceManager::GetInstance()->GetShader("Animation");
	m_Model = ResourceManager::GetInstance()->GetModel("Texture");
	m_Texture = ResourceManager::GetInstance()->GetTexture("poo_down.tga");

	m_spriteAnim = std::make_shared<SpriteAnimation2D>(m_Model, m_Shader, m_Texture, 6, 0.1f);

}

void Application::Update(GLfloat deltaTime)
{
	//std::cout << "Application::Update" << std::endl;
	m_spriteAnim->Update(deltaTime);
}

void Application::Draw()
{
	//m_sprite2d->Draw();
	m_spriteAnim->Draw();
}

void Application::HandleKeyEvent(int key, bool isPressed)
{
	//std::cout << "Key: " << key << " isPressed: " << isPressed << std::endl;
}

void Application::HandleTouchEvent(double xpos, double ypos, bool isPressed)
{

}