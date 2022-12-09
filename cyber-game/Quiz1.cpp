#include "Quiz1.h"
#include "DxLib.h"
#include "Pad.h"
#include "SceneMain.h"

namespace
{
	//constexpr int kWaitFrame = 90;
}

Quiz1::Quiz1()
{
	m_textCount = 0;
}

void Quiz1::init()
{
	m_hBg = LoadGraph("Data/titleBg1.jpg");

	m_text0 = LoadGraph("Data/suma0.png");
	m_text1 = LoadGraph("Data/suma1.png");
	m_text2 = LoadGraph("Data/suma2.png");

	// �x��
	m_text3 = LoadGraph("Data/police1.png");

	m_textNum = m_text0;

	
}

void Quiz1::update()
{
	if (m_textCount == 2)
	{
		m_textNum = m_text1;
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			SetFontSize(18);
			DrawString(230, 120, "  �҂��āI", GetColor(255, 255, 0));
			DrawString(230, 140, "�V���b�s���O�T�C�g�̃h���C�������m�F����B", GetColor(255, 255, 255));
			DrawString(230, 160, "�M���̂�����V���b�s���O�T�C�g�𗘗p����B", GetColor(255, 255, 255));
			DrawString(230, 180, "�������鉿�i���x����Ȃ��I", GetColor(255, 255, 255));
			DrawString(230, 200, "��ЊT�v�̏Z����A���悪���݂��邩�m�F����B", GetColor(255, 255, 255));
			DrawString(230, 220, "�x�����@����s�U���݂̂�������A", GetColor(255, 255, 255));
			DrawString(230, 240, " �U���悪�O���l����l���̏ꍇ�́A", GetColor(255, 255, 255));
			DrawString(230, 260, "  ���Ȃ�������I�I", GetColor(255, 255, 255));
		}
	}
	if (m_textCount == 3)
	{
		m_textNum = m_text2;
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			SetFontSize(20);
			DrawString(230, 120, "������U�荞��ł����i�������Ă��Ȃ�", GetColor(255, 255, 0));
			DrawString(230, 140, "�@�@�@�@�V���b�s���O�T�C�g�I", GetColor(255, 255, 0));
			DrawString(230, 170, "   ������L���b�V���J�[�h���Ȃǂ�", GetColor(255, 0, 0));
			DrawString(230, 190, "�@�@ �@  �@���܂�܂��I", GetColor(255, 0, 0));
		}
	}
}

void Quiz1::draw()
{
	DrawFormatString(0, 0, GetColor(0, 255, 255),
		"��P");
	DrawFormatString(20, 420, GetColor(0, 255, 255),
		"�X�y�[�X�L�[�Ŏ~�߂悤�I");
	SetFontSize(18);
	if (m_textCount == 1)
	{
		DrawString(0, 60, " �Ȃɒ��ׂ�����ȁ`", GetColor(255, 255, 255));
	}

	if (m_textCount == 2)
	{
		DrawString(0, 60, " �Ȃɂ��̃T�C�g�I�H", GetColor(255, 255, 255));
		DrawString(0, 100, " ����ȂɈ����I�I", GetColor(255, 255, 255));
		DrawString(0, 120, " �w���{�^�����N���b�N�I", GetColor(255, 255, 255));
	}
	if (m_textCount == 3)
	{
		DrawString(0, 60, " �J�`�b�E�E����H", GetColor(255, 255, 255));
		DrawString(0, 80, " 10���~...�H", GetColor(255, 255, 255));
	}
	if (m_textCount >= 4)
	{
		DrawFormatString(100, 150, GetColor(0, 0, 255),
			"�߂� �� BACKSPACE�@�@��Q �� �A�{�_��");
		//DrawString(0, 80, "10���~...�H", GetColor(255, 255, 255));
	}
	SetFontSize(24);
	ChangeFont("�l�r �S�V�b�N");
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		if (m_textCount == 1)
		{
			DrawString(50, 210, "�܂�����", GetColor(255,0,255));
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
			//WaitKey();

			return;
		}
		//m_waitFrame = 300;
	}
	
	DrawGraph(200, 0, m_textNum, false);

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
