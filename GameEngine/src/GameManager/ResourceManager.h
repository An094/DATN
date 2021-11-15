#pragma once
#include<iostream>
#include "GameObject/Texture.h"
#include "GameObject/shaderClass.h"
#include "GameObject/Model.h"
#include <map>


class ResourceManager //: public Singleton<ResourceManager>
{
public:
	ResourceManager();
	~ResourceManager();

	static std::shared_ptr<ResourceManager> GetInstance()
	{
		if (s_Instance == nullptr)
			s_Instance = std::make_shared<ResourceManager>();
		return s_Instance;
	}

	void AddShader(const std::string& name);
	void AddTexture(const std::string& name);
	void AddModel(const std::string& name);

	std::shared_ptr<Shader> GetShader(const std::string& name);
	std::shared_ptr<Texture> GetTexture(const std::string& name);
	std::shared_ptr<Model> GetModel(const std::string& name);

private:
	std::string m_ShaderPath;
	std::string m_TexturePath;
	std::string m_ModelPath;

	std::map<std::string, std::shared_ptr<Shader>> m_MapShader;
	std::map<std::string, std::shared_ptr<Texture>> m_MapTexture;
	std::map<std::string, std::shared_ptr<Model>> m_MapModel;

	static std::shared_ptr<ResourceManager> s_Instance;
};

