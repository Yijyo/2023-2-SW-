#include "BossSceneIntro.h"


void BossSceneIntro::StartBossScene() {
	COORD cursorPosition;
	cursorPosition.X = ConsoleSizeWidth / 2 - 18;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 10;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	cout << "Stage 2을 클리어했습니다! 이제 Stage 3로 이동합니다." << endl;
	cursorPosition.X = ConsoleSizeWidth / 2 - 18;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 9;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	cout << "보스 바이러스를 죽이세요!! 이번만 이기면 당신의 승리입니다!" << endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 18;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 8;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	cout << "<K> 키를 눌러 총알을 발사할 수 있습니다!" << endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 13;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	cout << "준비되셨다면 <Space Bar> 를 눌러주세요." << endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 15;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	cout << "▶";
}

void BossSceneIntro::UpdateBossScene() {
	char key;

	if (_kbhit()) {
		key = _getch();
		if (key == ' ') {
			BossScene bossScene;
			bossScene.isMainScene();
		}

	}
}

void BossSceneIntro::EndBossScene() {
	system("cls");
}