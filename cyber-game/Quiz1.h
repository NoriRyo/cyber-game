#pragma once
class Quiz1
{
public:
	Quiz1();
	~Quiz1(){}

	void init();
	void update();
	void draw();

private:
	// îwåi
	int m_hBg;

	int m_textCount;
	int m_textNum;
	int m_text0;
	int m_text1;
	int m_text2;
	int m_text3;

	int m_waitFrame;
};

