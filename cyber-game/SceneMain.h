#pragma once
#include "SceneBase.h"
#include "Vec2.h"
#include "Quiz1.h"
#include "Quiz2.h"

class SceneMain : public SceneBase
{
public:
	SceneMain();

	virtual ~SceneMain() {}

	virtual void init() override;
	virtual void end()  override;

	virtual SceneBase* update() override;
	virtual void draw() override;
	
private:

	int Stage;

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;

	Quiz1 quiz1;
	Quiz2 quiz2;

};