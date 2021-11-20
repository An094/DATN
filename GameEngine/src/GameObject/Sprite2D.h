#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Model;
class Shader;
class Texture;
class Sprite2D
{
private:
	std::shared_ptr<Model> m_Model;
	std::shared_ptr<Shader> m_Shader;
	std::shared_ptr<Texture> m_Texture;
	glm::vec2 m_Position;
	glm::mat4 m_TransMatrix;
	glm::mat4 m_RotateMatrix;
	glm::mat4 m_ScaleMatrix;
	int m_Width, m_Height;
public:
	Sprite2D(std::shared_ptr<Model>, std::shared_ptr<Shader>, std::shared_ptr<Texture>);
	Sprite2D(const std::string&, const std::string&, const std::string&);
	~Sprite2D();
	inline std::shared_ptr<Texture> GetTexture() { return m_Texture; }
	inline std::shared_ptr<Model> GetModel() { return m_Model; }
	inline std::shared_ptr<Shader> GetShader() { return m_Shader; }

	inline glm::mat4 GetTransMatrix() { return m_TransMatrix; }
	inline glm::mat4 GetRotateMatrix() { return m_RotateMatrix; }
	inline glm::mat4 GetScaleMatrix() { return m_ScaleMatrix; }


	void SetPosition(int xpos, int ypos);
	inline glm::vec2 GetPosition() { return m_Position; }

	void SetSize(int width, int height);
	inline void GetSize(int& width, int& height) {
		width = m_Width;
		height = m_Height;
	}
	void Init();
	void Draw();
};

