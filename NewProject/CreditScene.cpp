#include "CreditScene.h"
using namespace std;


string CreditScene::_creditString[4] = { "소프트웨어 설계기초 15조", "이지호 김동욱 구윤성 이바름", "재미있게 플레이 해주세요...", "학점 잘 받고 싶습니다..." };

void CreditScene::End()
{
	system("cls");
}

void CreditScene::Start()
{
	for (int i = 0; i < 4; i++)
	{
		COORD cursorPosition;
		cursorPosition.X = 50;
		cursorPosition.Y = 1.5 * i + 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
		cout << _creditString[i] << endl;
	}

	COORD cursorPosition;
	cursorPosition.X = ConsoleSizeWidth / 2 - 5;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	cout << "돌아가기" << endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 7;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	cout << "▶";
}

void CreditScene::Update()
{
	char key;
	if (_kbhit())
	{
		key = _getch();
		if (key == ' ')
		{
			SceneManager::ChangeScene(EScene::Intro);
			while (1)
			{
				SceneManager::Update(EScene::Intro);
			}
		}
	}
}
