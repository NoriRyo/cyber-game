#include "DxLib.h"
#include "game.h"
#include "SceneTitle.h"
#include "Pad.h"
#include "SceneMain.h"

namespace
{
	// �\�����镶����
	const char* const kTitleText = "�T�C�o�[�΍�Q�[��";
	const char* const kExplanationText = "��Ȃ��Ǝv�����Ƃ���Ŏ~�߂āI";
	const char* const kGuideText = "�X�y�[�X�������ăX�^�[�g�I";
	// ������_��
	constexpr int kTextDispFrame = 45;
	constexpr int kTextHideFrame = 15;

	// �����F
	const int kTitleFontColor = GetColor(255, 0, 0);

	const int kExplanationFontColor = GetColor(255, 0, 255);

	const int kFontColor = GetColor(255, 255, 255);

}

void SceneTitle::init()
{
	m_textBlinkFrame = 0;
	SetFontSize(32);

	m_hBg = LoadGraph("Data/titleBg1.jpg");
}

void SceneTitle::end()
{
	SetFontSize(16);
}

SceneBase* SceneTitle::update()
{
	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// �t�F�[�h�A�E�g�I�����ɃV�[���؂�ւ�
		if (!isFading() && isOut)
		{
			return (new SceneMain);
		}
	}
	// �e�L�X�g�̓_��
	m_textBlinkFrame++;
	if (m_textBlinkFrame >= kTextDispFrame + kTextHideFrame)
	{
		m_textBlinkFrame = 0;
	}
	if (!isFading())
	{
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			// �t�F�[�h�A�E�g�J�n
			startFadeOut();
		}
	}
	return this;
}

void SceneTitle::draw()
{
	DrawGraph(0, 0, m_hBg, false);

	int width = GetDrawStringWidth(kTitleText, static_cast<int>(strlen(kTitleText)));
	SetFontSize(52);
	DrawString(Game::kScreenWidth / 2 - width, 140, kTitleText, kTitleFontColor);
	SetFontSize(24);
	DrawString(Game::kScreenWidth / 2 / 2, 230, kExplanationText, kExplanationFontColor);

	if (m_textBlinkFrame < kTextDispFrame)
	{
		width = GetDrawStringWidth(kGuideText, static_cast<int>(strlen(kGuideText)));
		DrawString(Game::kScreenWidth / 2 - width / 2, 350, kGuideText, kFontColor);
	}

	SceneBase::drawFade();
}