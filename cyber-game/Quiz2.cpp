// ��Q

#include "Quiz2.h"
#include "Quiz1.h"
#include "DxLib.h"

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

// �X�y�[�X���������Ƃ��̑Ή�����
void Quiz2::update()
{
	if (m_textCount == 1)
	{
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			SetFontSize(18);
			DrawString(230, 120, "  �҂��āI", GetColor(255, 255, 0));
			DrawString(230, 140, "SMS�̃����N���΂ɊJ���Ȃ�", GetColor(255, 255, 255));
			DrawString(230, 160, "�������h���C�������m�F����", GetColor(255, 255, 255));
			DrawString(230, 180, "��{�I��SMS�̓��e��M�p���Ȃ�", GetColor(255, 255, 255));
			DrawString(230, 200, "�Ȃ肷�܂��̃��[���ɂ�����", GetColor(255, 255, 255));
			DrawString(230, 220, "���K�T�C�g���u�b�N�}�[�N�ɓo�^���A", GetColor(255, 255, 255));
			DrawString(230, 240, " ��������ڑ�����", GetColor(255, 255, 255));
		}
	}
	if (m_textCount == 2)
	{
		m_textNum = m_text1;
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			SetFontSize(18);
			DrawString(230, 120, "  �҂��āI", GetColor(255, 255, 0));
			DrawString(230, 140, "�����N���J�����Ƃ��Ă��A", GetColor(255, 255, 255));
			DrawString(230, 160, " ���O�C������J�[�h���Ȃǂ���͂��Ȃ�", GetColor(255, 255, 255));
		}
	}
	if (m_textCount == 3)
	{
		m_textNum = m_text2;
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			SetFontSize(18);
			DrawString(200, 105, "����́A�A", GetColor(255, 255, 255));
			DrawString(200, 130, "���݂����Г��𑕂������[����", GetColor(255, 255, 0));
			DrawString(200, 150, "�V���[�g���b�Z�[�W�𑗂���A", GetColor(255, 255, 0));
			DrawString(200, 170, "���[�����ɋL�ڂ��ꂽ�����N����{�����������", GetColor(255, 255, 0));
			DrawString(200, 190, "�U�T�C�g�֗U�����A", GetColor(255, 0, 0));//
			DrawString(200, 210, "ID�E�p�X���[�h���̌l����", GetColor(255, 255, 0));
			DrawString(200, 230, "���͂����ē��ݎ����", GetColor(255, 0, 0));//
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
		if (!CheckHitKey(KEY_INPUT_SPACE))
		{
			DrawGraph(330, 230, m_text4, true);
		}
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
	// �₪�I������Ƃ��̏���
	if (m_textCount >= 4)
	{
		m_textNum = 0;
		DrawFormatString(100, 150, GetColor(0, 0, 255),
			"�߂� �� BACKSPACE�@�@��P �� �@�{�_��");
		//DrawString(0, 80, "10���~...�H", GetColor(255, 255, 255));
	}
	SetFontSize(24);
	ChangeFont("�l�r �S�V�b�N");

	//	�X�y�[�X���������Ƃ��̌x��
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		if (m_textCount == 1)
		{
			// �x��
			DrawGraph(-12, 150, m_text3, false);
			DrawString(50, 210, "�X�g�b�v!�I", GetColor(255, 0, 0));
			return;
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

	//�@�e�L�X�g��\��
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
