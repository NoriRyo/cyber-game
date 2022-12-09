#pragma once
class Quiz2
{
public:
	Quiz2();
	~Quiz2() {}

	void init();
	void update();
	void draw();

private:
	int m_textCount;
	int m_textNum;
	int m_text0;
	int m_text1;
	int m_text2;
	int m_text3;
	int m_text4;

	int m_waitFrame;
};

