#include "ClearScene.h"

void ClearScene::Start() {
	COORD cursorPosition;
	cursorPosition.X = ConsoleSizeWidth / 2 - 21;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	cout << "당신은 이 모든 위협 속에서 결국 살아남았습니다..." << endl;
	cursorPosition.X = ConsoleSizeWidth / 2 - 21;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	cout << "그리고 개강을 해버렸습니다... 학교로 다시 가세요." << endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 5;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	cout << "처음으로" << endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 7;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	cout << "▶";
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