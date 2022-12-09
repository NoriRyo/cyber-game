#include "SceneMain.h"
#include "DxLib.h"
#include "SceneTitle.h"
#include "Pad.h"
#include "quiz1.h"
#include "quiz2.h"


SceneMain::SceneMain()
{
	Stage = 0;
}

void SceneMain::init()
{
	quiz1.init();
	
	quiz2.init();
}

void SceneMain::end()
{
}

SceneBase* SceneMain::update()
{
	if (CheckHitKey(KEY_INPUT_1))
	{
		Stage = 1;
	}
	
	if (CheckHitKey(KEY_INPUT_2))
	{
		Stage = 2;
	}

	if (CheckHitKey(KEY_INPUT_BACK))
	{
		Stage = 5;
	}

	if (Stage == 1)
	{
		quiz1.update();
	}
	
	else if (Stage == 2)
	{
		quiz2.update();
	}

	if (Stage == 5)
	{
		return (new SceneTitle);
	}
}

void SceneMain::draw()
{
	SetFontSize(24);
	
	if (Stage == 0)
	{
		DrawFormatString(100, 150, GetColor(0, 0, 255),
			"ñ‚ÇP Å® á@É{É_ÉìÅ@Å@ñ‚ÇQ Å® áAÉ{É_Éì");
	}

	
	if (Stage == 1)
	{
		quiz1.draw();
	}
	
	else if (Stage == 2)
	{
		quiz2.draw();
	}
}
