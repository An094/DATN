#pragma once
#include "Sprite2D.h"
class SpriteAnimation2D : public Sprite2D
{
public:
	SpriteAnimation2D(std::shared_ptr<Model>, std::shared_ptr<Shader>, std::shared_ptr<Texture>, int, float);
	SpriteAnimation2D(const std::string&, const std::string&, const std::string&, int, float);
	~SpriteAnimation2D();

	void Init();
	void Draw();
	void Update(float);
private:
	int m_CurrentFrame;
	float m_CurrentTime;
	int m_NumberFrame;
	float m_FrameTime;
};

