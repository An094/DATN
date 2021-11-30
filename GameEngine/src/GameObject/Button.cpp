#include "Button.h"
#include <glad/glad.h>

Button::Button(const std::string& textureName, const std::string& modelName, const std::string& shaderName, ButtonType type)
	: Sprite2D(textureName, modelName, shaderName)
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
		bool firstCondition = xpos >= GetPosition().x - width * 0.5f && xpos <= GetPosition().x + width * 0.5f;
		bool secondCondition = ypos >= GetPosition().y - height * 0.5f && ypos <= GetPosition().y + height * 0.5f;
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