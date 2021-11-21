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
	Button(std::shared_ptr<Model>, std::shared_ptr<Shader>, std::shared_ptr<Texture>, ButtonType type = ButtonType::RECTANGLE);
	Button(const std::string&, const std::string&, const std::string&, ButtonType type = ButtonType::RECTANGLE);
	~Button();
	void SetOnClick(void (*)());
	void HandleTouchEvent(double xpos, double ypos, bool isPressed);
private:
	void (*Callback)();
	ButtonType m_Type;
};

