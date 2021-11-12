#pragma once
#include "utilities.h"
class Window
{
private:
	GLFWwindow* m_window;
	GLint m_width;
	GLint m_height;
	std::string m_name;
public:
	Window(GLint, GLint, std::string);
	~Window();
	inline GLFWwindow* getWindow() { return m_window; }
	void Init();
	void Update(GLfloat deltaTime);
	void Draw();
	void Run();

};
