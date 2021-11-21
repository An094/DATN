#include "Button.h"
#include <glad/glad.h>

extern GLint heightScreen;

Button::Button(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, ButtonType type)
	: Sprite2D(model, shader, texture)
{
	m_Type = type;
}

Button::Button(const std::string& modelName, const std::string& shaderName, const std::string& textureName, ButtonType type)
	: Sprite2D(modelName, shaderName, textureName)
{
	m_Type = type;
}

Button::~Button()
{

}

void Button::HandleTouchEvent(double xpos, double ypos, bool isPressed)
{
	int width, height;
	GetSize(width, height);
	bool condition;
	if (m_Type == ButtonType::RECTANGLE)
	{
		//Origin Coordinate of OpenGL is in Top Left corner but in the Engine it is Bottom Left corner
		bool firstCondition = xpos >= GetPosition().x - width * 0.5f && xpos <= GetPosition().x + width * 0.5f;
		bool secondCondition = ypos >= (heightScreen - GetPosition().y) - height * 0.5f && ypos <= (heightScreen - GetPosition().y) + height * 0.5f;
		condition = firstCondition && secondCondition;
	}
	else
	{
		condition = pow(GetPosition().x - xpos, 2) + pow(GetPosition().y - ypos, 2) <= pow(width * 0.5, 2);
	}
	if (condition && !isPressed)
	{
		Callback();
	}
}

void Button::SetOnClick(void (*callback)())
{
	Callback = callback;
}