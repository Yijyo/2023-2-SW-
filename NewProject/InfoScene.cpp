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
	std::cout << "�� ������ �ٰ����� �����κ��� �������� ��Ƴ��� �����Դϴ�." << std::endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 20;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 8;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "����� ���� �����߸��� ������ �� �ֽ��ϴ�." << std::endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 21;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 7;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "������ ������ ���ο� �ɷ��� ���� �� �ֽ��ϴ�." << std::endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 27;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "���� �ɷ��� �����鼭 �ٰ����� �����κ��� �¼� �ο켼��!!" << std::endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 12;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "�̵� - W / A / S / D" << std::endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 8;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "���� - �ڵ�" << std::endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 7;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "���ư���" << std::endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 15;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	std::cout << "��";
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
