#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	std::string dataPath = "..\\Data\\";
	m_ShaderPath = dataPath + "Shaders\\";
	m_TexturePath = dataPath + "Textures\\";
}

void ResourceManager::AddShader(const std::string& name)
{
	auto it = m_MapShader.find(name);
	if (it != m_MapShader.end())
	{
		return;
	}

	std::shared_ptr<Shader>  shaders;
	std::string vs = m_ShaderPath + name + ".vs";
	std::string fs = m_ShaderPath + name + ".fs";
	shaders = std::make_shared<Shader>(vs.c_str(),fs.c_str());

	//shaders->Init(vs, fs);

	m_MapShader.insert(std::pair<std::string, std::shared_ptr<Shader>>(name, shaders));
}

void ResourceManager::AddTexture(const std::string& name)
{
	auto it = m_MapTexture.find(name);
	if (it != m_MapTexture.end())
	{
		return;
	}
	//std::shared_ptr<Texture> texture = std::make_shared<Texture>();
	//std::string file = m_TexturePath + name + ".tga";
	////texture->Init(file.c_str(), GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	//m_MapTexture.insert(std::pair<std::string, std::shared_ptr<Texture>>(name, texture));
}

std::shared_ptr<Shader> ResourceManager::GetShader(const std::string& name)
{
	auto it = m_MapShader.find(name);
	if (it != m_MapShader.end())
	{
		return it->second;
	}

	std::shared_ptr<Shader>  shader;
	std::string vs = m_ShaderPath + name + ".vs";
	std::string fs = m_ShaderPath + name + ".fs";
	shader = std::make_shared<Shader>(vs.c_str(),fs.c_str());

	//shaders->Init(vs, fs);

	m_MapShader.insert(std::pair<std::string, std::shared_ptr<Shader>>(name, shader));

	return shader;
}

std::shared_ptr<Texture> ResourceManager::GetTexture(const std::string& name)
{
	auto it = m_MapTexture.find(name);
	if (it != m_MapTexture.end())
	{
		return it->second;
	}
	//std::shared_ptr<Texture> texture = std::make_shared<Texture>();
	//std::string file = m_TexturePath + name + ".tga";
	////texture->Init(file.c_str(), GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	//m_MapTexture.insert(std::pair<std::string, std::shared_ptr<Texture>>(name, texture));
	//return texture;
}