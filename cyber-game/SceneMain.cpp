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
	//　１ボタン
	if (CheckHitKey(KEY_INPUT_1))
	{
		Stage = 1;
	}
	
	//　２ボタン
	if (CheckHitKey(KEY_INPUT_2))
	{
		Stage = 2;
	}

	//　バックスペース
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
	SetFontSize(30);
	int m_waitFrame = 0;
	
	if (Stage == 0)
	{
		DrawFormatString(40, 150, GetColor(0, 0, 255),
			"問１ → ①ボタン　　問２ → ②ボタン");
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
