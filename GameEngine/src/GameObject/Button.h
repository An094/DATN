#pragma once

#include "Sprite2D.h"

class Button : public Sprite2D
{
public:
	Button(std::shared_ptr<Model>, std::shared_ptr<Shader>, std::shared_ptr<Texture>);
	~Button();
	void SetOnClick(void (*)());
	void HandleTouchEvent(double xpos, double ypos, bool isPressed);
private:
	void (*Callback)();

};

