#include "MainScene2Intro.h"


void MainScene2Intro::Start() {
    COORD cursorPosition;
    cursorPosition.X = ConsoleSizeWidth / 2 - 18;
    cursorPosition.Y = ConsoleSizeHeight / 2 - 10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
    cout << "Stage 1�� Ŭ�����߽��ϴ�! ���� Stage 2�� �̵��մϴ�." << endl;
    cursorPosition.X = ConsoleSizeWidth / 2 - 32;
    cursorPosition.Y = ConsoleSizeHeight / 2 - 9;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
    cout << "����� ������Ű�� �ٰ����� ���̷����� ���̼���! ��ġ�� ����� ��ġ�� �˴ϴ�.." << endl;

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

void MainScene2Intro::Update() {
    char key;

    if (_kbhit()) {
        key = _getch();
        if (key == ' ') {
            MainScene2 mainScene2;
            mainScene2.isMainScene();
        }

    }
}

void MainScene2Intro::End() {
    system("cls");
}