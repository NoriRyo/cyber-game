#include "Quiz2.h"
#include "Quiz1.h"
#include "DxLib.h"

namespace
{
	//constexpr int kWaitFrame = 90;
}

Quiz2::Quiz2()
{
	m_textCount = 0;
}

void Quiz2::init()
{
	m_text4 = LoadGraph("Data/paso0.png");
	m_text0 = LoadGraph("Data/paso1.png");
	m_text1 = LoadGraph("Data/paso2.png");
	m_text2 = LoadGraph("Data/paso3.png");

	// �x��
	m_text3 = LoadGraph("Data/police1.png");

	m_textNum = m_text0;


}

void Quiz2::update()
{
	// �������Ƃ��̃��b�Z�[�W
	if (m_textCount == 2)
	{
		m_textNum = m_text1;
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			SetFontSize(18);
			DrawString(230, 120, "  �҂��āI", GetColor(255, 255, 0));
			DrawString(230, 140, "", GetColor(255, 255, 255));
			DrawString(230, 160, "", GetColor(255, 255, 255));
			DrawString(230, 180, "", GetColor(255, 255, 255));
			DrawString(230, 200, "", GetColor(255, 255, 255));
			DrawString(230, 220, "", GetColor(255, 255, 255));
			DrawString(230, 240, "", GetColor(255, 255, 255));
			DrawString(230, 260, "", GetColor(255, 255, 255));
		}
	}
	if (m_textCount == 3)
	{
		m_textNum = m_text2;
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			SetFontSize(20);
			DrawString(230, 120, "", GetColor(255, 255, 255));
			DrawString(230, 140, "", GetColor(255, 255, 255));
			DrawString(230, 170, "", GetColor(255, 0, 0));
			DrawString(230, 190, "", GetColor(255, 0, 0));
		}
	}
}

void Quiz2::draw()
{
	DrawFormatString(0, 0, GetColor(0, 255, 255),
		"��Q");
	DrawFormatString(20, 420, GetColor(0, 255, 255),
		"�X�y�[�X�L�[�Ŏ~�߂悤�I");
	
	SetFontSize(18);
	if (m_textCount == 1)
	{
		DrawGraph(330, 230, m_text4, true);
		DrawString(0, 60, "�ȂɂȂ�...", GetColor(255, 255, 255));
		DrawString(0, 80, "�x�����ɖ��H", GetColor(255, 255, 255));
	}
	if (m_textCount == 2)
	{
		DrawString(0, 60,  "�p�X���[�h��", GetColor(255, 255, 255));
		DrawString(0, 80, "���͂����炢���̂�", GetColor(255, 255, 255));
		DrawString(0, 100, "", GetColor(255, 255, 255));
	}
	if (m_textCount == 3)
	{
		DrawString(0, 60, "", GetColor(255, 255, 255));
		DrawString(0, 80, "", GetColor(255, 255, 255));
	}
	if (m_textCount >= 4)
	{
		DrawFormatString(100, 380, GetColor(0, 0, 255),
			"�߂� �� BACKSPACE�@�@��P �� �@�{�_��");
		//DrawString(0, 80, "10���~...�H", GetColor(255, 255, 255));
	}
	SetFontSize(24);
	ChangeFont("�l�r �S�V�b�N");
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		if (m_textCount == 1)
		{
			DrawString(50, 210, "�܂�����", GetColor(255, 0, 255));
		}
		if (m_textCount == 2)
		{
			// �x��
			DrawGraph(-12, 150, m_text3, false);
			DrawString(0, 210, "�X�g�b�v�I�I", GetColor(255, 0, 0));
			return;

		}
		if (m_textCount == 3)
		{
			DrawString(32, 210, "�A�E�g", GetColor(255, 0, 0));
			return;
		}
	}

	DrawGraph(200, 0, m_textNum, false);

	// �\������
	if (m_waitFrame > 0)
	{
		clsDx();
		printfDx("\n\n%d", m_waitFrame);
		m_waitFrame--;
		return;
	}
	m_textCount++;
	m_waitFrame = 300;
}
