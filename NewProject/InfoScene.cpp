#include "InfoScene.h"

void InfoScene::End()
{
	system("cls");
}

void InfoScene::Start()
{
	COORD cursorPosition;
	cursorPosition.X = ConsoleSizeWidth / 2 - 12;
	cursorPosition.Y = 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	std::cout << "Escape From Pandemic" << std::endl;
	cursorPosition.X = ConsoleSizeWidth / 2 - 28;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 9;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "이 게임은 다가오는 적으로부터 오랫동안 살아남는 게임입니다." << std::endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 20;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 8;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "당신은 적을 쓰러뜨리며 성장할 수 있습니다." << std::endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 21;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 7;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "성장할 때마다 새로운 능력을 얻을 수 있습니다." << std::endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 27;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "여러 능력을 얻으면서 다가오는 적으로부터 맞서 싸우세요!!" << std::endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 12;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "이동 - W / A / S / D" << std::endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 8;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "공격 - 자동" << std::endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 7;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "돌아가기" << std::endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 15;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "▶";
}

void InfoScene::Update()
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
