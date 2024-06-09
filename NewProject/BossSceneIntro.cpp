#include "BossSceneIntro.h"


void BossSceneIntro::StartBossScene() {
	COORD cursorPosition;
	cursorPosition.X = ConsoleSizeWidth / 2 - 18;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 10;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	cout << "Stage 2�� Ŭ�����߽��ϴ�! ���� Stage 3�� �̵��մϴ�." << endl;
	cursorPosition.X = ConsoleSizeWidth / 2 - 18;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 9;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	cout << "���� ���̷����� ���̼���!! �̹��� �̱�� ����� �¸��Դϴ�!" << endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 18;
	cursorPosition.Y = ConsoleSizeHeight / 2 - 8;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	cout << "<K> Ű�� ���� �Ѿ��� �߻��� �� �ֽ��ϴ�!" << endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 13;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	cout << "�غ�Ǽ̴ٸ� <Space Bar> �� �����ּ���." << endl;

	cursorPosition.X = ConsoleSizeWidth / 2 - 15;
	cursorPosition.Y = ConsoleSizeHeight / 2 + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	cout << "��";
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