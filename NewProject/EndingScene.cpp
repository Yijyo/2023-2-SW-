#include "EndingScene.h"
#include "Player.h"

int EndingScene::servivedTime;
int EndingScene::killCount;

void EndingScene::Start()
{
	COORD cursorPosition;
	cursorPosition.X = ConsoleSizeWidth / 2 - 10;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 10;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	cout << "당신은 죽어버렸습니다." << endl;
	cursorPosition.X = ConsoleSizeWidth / 2 - 10;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 9;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	cout << "살아남은 시간 : " << to_string(servivedTime)	+ "s" << endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 10;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 8;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	cout << "쓰러뜨린 적 : " << to_string(killCount) + "마리" << endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 5;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	cout << "처음으로" << endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 7;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	cout << "▶";
}

void EndingScene::Update()
{
	char key;

	if (_kbhit()) {
		key = _getch();
		if (key == ' ') {
			SceneManager::ChangeScene(EScene::Intro);
			while (1) {
				SceneManager::Update(EScene::Intro);
			}
		}
		
	}
}

void EndingScene::End()
{
	system("cls");
}
