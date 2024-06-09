#include "MainScene2Intro.h"


void MainScene2Intro::Start() {
    COORD cursorPosition;
    cursorPosition.X = ConsoleSizeWidth / 2 - 18;
    cursorPosition.Y = ConsoleSizeHeight / 2 - 10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
    cout << "Stage 1을 클리어했습니다! 이제 Stage 2로 이동합니다." << endl;
    cursorPosition.X = ConsoleSizeWidth / 2 - 32;
    cursorPosition.Y = ConsoleSizeHeight / 2 - 9;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
    cout << "당신을 감염시키러 다가오는 바이러스를 죽이세요! 놓치면 당신은 다치게 됩니다.." << endl;

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