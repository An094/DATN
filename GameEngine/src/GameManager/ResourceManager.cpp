#include "ResourceManager.h"
#include "Common.h"

std::shared_ptr<ResourceManager> ResourceManager::s_Instance = nullptr;

std::shared_ptr<ResourceManager> ResourceManager::GetInstance()
{
	if (s_Instance == nullptr)
		s_Instance = std::make_shared<ResourceManager>();
	return s_Instance;
}

ResourceManager::ResourceManager()
{
	m_DataPath = "../GameEngine/Data/";
	m_ShaderPath = m_DataPath + "Shaders/";
	m_TexturePath = m_DataPath + "Textures/";
	m_ModelPath = m_DataPath + "Models/";
}

ResourceManager::~ResourceManager()
{

}
//Load data from files named in Data.inl
void ResourceManager::Init()
{
	std::string initFileName = m_DataPath + "Data.inl";
	std::string buffer = Common::get_file_contents(initFileName.c_str());
	std::stringstream ss(buffer);
	std::string strtmp;
	int numModel, numShader;
	std::getline(ss, strtmp, '\n');
	sscanf_s(strtmp.c_str(), "#Models %d", &numModel);
	for (int i = 0; i < numModel; i++)
	{
		std::getline(ss, strtmp, '\n');
		strtmp = strtmp.substr(0, strtmp.size() - 1);
		AddModel(strtmp);
	}
	std::getline(ss, strtmp, '\n');
	sscanf_s(strtmp.c_str(), "#Shaders %d", &numShader);
	for (int i = 0; i < numShader; i++)
	{
		std::getline(ss, strtmp, '\n');
		strtmp = strtmp.substr(0, strtmp.size() - 1);
		AddShader(strtmp);
	}
}

void ResourceManager::AddShader(const std::string& name)
{
	std::map<std::string, std::shared_ptr<Shader>>::iterator it = m_MapShader.find(name);
	if (it != m_MapShader.end())
	{
		return;
	}

	std::shared_ptr<Shader>  shader;
	std::string vsPath = m_ShaderPath + name + ".vs";
	std::string fsPath = m_ShaderPath + name + ".fs";
	shader = std::make_shared<Shader>(vsPath.c_str(), fsPath.c_str());

	m_MapShader[name] = shader;

}

void ResourceManager::AddModel(const std::string& name)
{
	std::map<std::string, std::shared_ptr<Model>>::iterator it = m_MapModel.find(name);
	if (it != m_MapModel.end())
	{
		return;
	}
	std::shared_ptr<Model>  model;
	std::string path = m_ModelPath + name + ".txt";
	model = std::make_shared<Model>(path.c_str());

	m_MapModel[name] = model;

}

void ResourceManager::AddTexture(const std::string& name)
{
	std::map<std::string, std::shared_ptr<Texture>>::iterator it = m_MapTexture.find(name);
	if (it != m_MapTexture.end())
	{
		return;
	}
	std::shared_ptr<Texture> texture;
	std::string path = m_TexturePath + name;
	texture = std::make_shared<Texture>(path.c_str());

	m_MapTexture[name] = texture;
}

std::shared_ptr<Model> ResourceManager::GetModel(const std::string& name)
{
	std::map<std::string, std::shared_ptr<Model>>::iterator  it = m_MapModel.find(name);
	if (it != m_MapModel.end())
	{
		return it->second;
	}

	std::shared_ptr<Model>  model;
	std::string path = m_ModelPath + name + ".txt";
	model = std::make_shared<Model>(path.c_str());
	return model;
}

std::shared_ptr<Shader> ResourceManager::GetShader(const std::string& name)
{
	std::map<std::string, std::shared_ptr<Shader>>::iterator  it = m_MapShader.find(name);
	if (it != m_MapShader.end())
	{
		return it->second;
	}

	std::shared_ptr<Shader>  shader;
	std::string vs = m_ShaderPath + name + ".vs";
	std::string fs = m_ShaderPath + name + ".fs";
	shader = std::make_shared<Shader>(vs.c_str(),fs.c_str());
	return shader;
}

std::shared_ptr<Texture> ResourceManager::GetTexture(const std::string& name)
{
	std::map<std::string, std::shared_ptr<Texture>>::iterator it = m_MapTexture.find(name);
	if (it != m_MapTexture.end())
	{
		return it->second;
	}

	std::shared_ptr<Texture> texture;
	std::string path = m_TexturePath + name;
	texture = std::make_shared<Texture>(path.c_str());

	return texture;
}
