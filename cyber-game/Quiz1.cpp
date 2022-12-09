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

	// 警官
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
			DrawString(230, 120, "  待って！", GetColor(255, 255, 0));
			DrawString(230, 140, "ショッピングサイトのドメイン名を確認する。", GetColor(255, 255, 255));
			DrawString(230, 160, "信頼のおけるショッピングサイトを利用する。", GetColor(255, 255, 255));
			DrawString(230, 180, "安すぎる価格に騙されない！", GetColor(255, 255, 255));
			DrawString(230, 200, "会社概要の住所や連絡先が実在するか確認する。", GetColor(255, 255, 255));
			DrawString(230, 220, "支払方法が銀行振込のみだったり、", GetColor(255, 255, 255));
			DrawString(230, 240, " 振込先が外国人名や個人名の場合は、", GetColor(255, 255, 255));
			DrawString(230, 260, "  かなり怪しい！！", GetColor(255, 255, 255));
		}
	}
	if (m_textCount == 3)
	{
		m_textNum = m_text2;
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			SetFontSize(20);
			DrawString(230, 120, "お金を振り込んでも商品が送られてこない", GetColor(255, 255, 0));
			DrawString(230, 140, "　　　　ショッピングサイト！", GetColor(255, 255, 0));
			DrawString(230, 170, "   お金やキャッシュカード情報などが", GetColor(255, 0, 0));
			DrawString(230, 190, "　　 　  　盗まれます！", GetColor(255, 0, 0));
		}
	}
}

void Quiz1::draw()
{
	DrawFormatString(0, 0, GetColor(0, 255, 255),
		"問１");
	DrawFormatString(20, 420, GetColor(0, 255, 255),
		"スペースキーで止めよう！");
	SetFontSize(18);
	if (m_textCount == 1)
	{
		DrawString(0, 60, " なに調べよっかな～", GetColor(255, 255, 255));
	}

	if (m_textCount == 2)
	{
		DrawString(0, 60, " なにこのサイト！？", GetColor(255, 255, 255));
		DrawString(0, 100, " こんなに安い！！", GetColor(255, 255, 255));
		DrawString(0, 120, " 購入ボタンをクリック！", GetColor(255, 255, 255));
	}
	if (m_textCount == 3)
	{
		DrawString(0, 60, " カチッ・・あれ？", GetColor(255, 255, 255));
		DrawString(0, 80, " 10万円...？", GetColor(255, 255, 255));
	}
	if (m_textCount >= 4)
	{
		DrawFormatString(100, 150, GetColor(0, 0, 255),
			"戻る → BACKSPACE　　問２ → ②ボダン");
		//DrawString(0, 80, "10万円...？", GetColor(255, 255, 255));
	}
	SetFontSize(24);
	ChangeFont("ＭＳ ゴシック");
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		if (m_textCount == 1)
		{
			DrawString(50, 210, "まだ早い", GetColor(255,0,255));
		}
		if (m_textCount == 2)
		{
			// 警官
			DrawGraph(-12, 150, m_text3, false);
			DrawString(0, 210, "ストップ！！", GetColor(255, 0, 0)); 
			return;
			
		}
		if (m_textCount == 3)
		{
			DrawString(32, 210, "アウト", GetColor(255, 0, 0));
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
