#pragma once

#include "Sprite2D.h"

enum ButtonType
{
	RECTANGLE = 0,
	CIRCLE
};

class Button : public Sprite2D
{
public:
	Button(const std::string&, const std::string& model = "Texture", const std::string& shader = "Texture", ButtonType type = ButtonType::RECTANGLE);
	~Button();
	void SetOnClick(void (*)());
	void HandleTouchEvent(double xpos, double ypos, bool isPressed);
private:
	void (*Callback)();
	ButtonType m_Type;
};

