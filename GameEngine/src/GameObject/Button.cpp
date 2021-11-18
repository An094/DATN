#include "Button.h"
#include <glad/glad.h>

extern GLint heightScreen;

Button::Button(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(model, shader, texture)
{

}

Button::~Button()
{

}

void Button::HandleTouchEvent(double xpos, double ypos, bool isPressed)
{
	int width, height;
	GetSize(width, height);
	//Origin Coordinate of OpenGL is in Top Left corner but in the Engine it is Bottom Left corner
	bool firstCondition = xpos >= GetPosition().x - width * 0.5f && xpos <= GetPosition().x + width * 0.5f;
	bool secondCondition = ypos >= (heightScreen - GetPosition().y) - height * 0.5f && ypos <= (heightScreen - GetPosition().y) + height * 0.5f;
	if (firstCondition && secondCondition && !isPressed)
	{
		Callback();
	}
}

void Button::SetOnClick(void (*callback)())
{
	Callback = callback;
}