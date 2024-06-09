#include "ClearScene.h"

void ClearScene::Start() {
	COORD cursorPosition;
	cursorPosition.X = ConsoleSizeWidth / 2 - 21;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	cout << "����� �� ��� ���� �ӿ��� �ᱹ ��Ƴ��ҽ��ϴ�..." << endl;
	cursorPosition.X = ConsoleSizeWidth / 2 - 21;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	cout << "�׸��� ������ �ع��Ƚ��ϴ�... �б��� �ٽ� ������." << endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 5;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	cout << "ó������" << endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 7;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	cout << "��";
}

void ClearScene::Update() {
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

void ClearScene::End() {
	system("cls");
}