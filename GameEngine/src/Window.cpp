#include "Window.h"

Window::Window(GLint width, GLint height, std::string name)
	: m_width(width), m_height(height), m_name(name)
{
	m_window = NULL;
	Init();
}

Window::~Window()
{

}

void Window::Init()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	// Create a GLFWwindow object of m_width by m_height pixels
	m_window = glfwCreateWindow(m_width, m_height, m_name.c_str(), NULL, NULL);
	// Error check if the window fails to create
	if (m_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(m_window);


	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = width, y = height
	glViewport(0, 0, m_width, m_height);



	// Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap the back buffer with the front buffer
	glfwSwapBuffers(m_window);
}

void Window::Update(GLfloat deltaTime)
{
	return;
}

void Window::Draw()
{
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Todo


	// Swap the back buffer with the front buffer
	glfwSwapBuffers(m_window);
	return;
}



void Window::Run()
{
	GLfloat deltaTime = 0.0f;
	GLfloat lastTime = 0.0f;
	GLfloat currentTime = 0.0f;
	// Main while loop
	while (!glfwWindowShouldClose(m_window))
	{
		currentTime = (float)glfwGetTime();
		//std::cout << "currentTime:" << currentTime << std::endl;
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		//std::cout << "deltaTime:" << deltaTime << std::endl;


		Update(deltaTime);
		Draw();

		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete window before ending the program
	glfwDestroyWindow(m_window);
	// Terminate GLFW before ending the program
	glfwTerminate();
}