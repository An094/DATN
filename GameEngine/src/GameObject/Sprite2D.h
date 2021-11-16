#pragma once
#include <iostream>

class Model;
class Shader;
class Texture;
class Sprite2D
{
private:
	std::shared_ptr<Model> m_Model;
	std::shared_ptr<Texture> m_Texture;
	std::shared_ptr<Shader> m_Shader;
	int m_xPos, m_yPos;
public:
	Sprite2D(std::shared_ptr<Model>, std::shared_ptr<Texture>, std::shared_ptr<Shader>);
	~Sprite2D();

	void SetPosition();
};

