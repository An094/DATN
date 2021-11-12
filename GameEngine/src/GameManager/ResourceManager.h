#pragma once
#include "GameObject/Texture.h"
#include "GameObject/shaderClass.h"
#include <map>


class ResourceManager //: public Singleton<ResourceManager>
{
public:
	ResourceManager();
	~ResourceManager();

	void AddShader(const std::string& name);
	void AddTexture(const std::string& name);

	std::shared_ptr<Shader> GetShader(const std::string& name);
	std::shared_ptr<Texture> GetTexture(const std::string& name);

private:
	std::string m_ShaderPath;
	std::string m_TexturePath;
	
	std::map<std::string, std::shared_ptr<Shader>> m_MapShader;
	std::map<std::string, std::shared_ptr<Texture>> m_MapTexture;
};

