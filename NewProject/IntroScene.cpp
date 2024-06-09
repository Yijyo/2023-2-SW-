#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "SceneManager.h"
#include "Utility.h"

namespace IntroScene {
    int index = 0;

    int getIndex() {
        return index;
    }

    void setIndex(int value) {
        index = Utility::Clamp(value, 0, 3);
    }

    void End() {
        system("cls");

        /*
        for (int i = 0; i < ConsoleSizeHeight; i++) {
            for (int j = 0; j < ConsoleSizeWidth; j++) {
                std::cout << ' ';
            }
            std::cout << std::endl;
        }*/
    }

    void Start() {
        setIndex(0);

        COORD cursorPosition;
        cursorPosition.X = ConsoleSizeWidth / 2 - 10;
        cursorPosition.Y = ConsoleSizeHeight / 2 - 8;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
        
        std::cout << "~~Escape From Pandemic~~" << std::endl;
        cursorPosition.Y += 5;
        cursorPosition.X = ConsoleSizeWidth / 2 - 1;



        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);// ÁÂÇ¥ Àâ°í
        std::cout << "Start" << std::endl;
        cursorPosition.Y += 2;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
        std::cout << "Info" << std::endl;
        cursorPosition.Y += 2;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
        std::cout << "Credit" << std::endl;
        cursorPosition.Y += 2;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
        std::cout << "Exit" << std::endl;

        cursorPosition.X = ConsoleSizeWidth / 2 - 8;
        cursorPosition.Y = ConsoleSizeHeight / 2 - 3 ;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
        std::cout << "¢º";
    }

    void Update() {
        if (_kbhit()) {
            char key = _getch();

            COORD cursorPosition;
            cursorPosition.X = ConsoleSizeWidth / 2 - 8;
            cursorPosition.Y = ConsoleSizeHeight / 2 -3 + getIndex() * 2;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
            std::cout << "  ";

            if (key == 'w') {
                setIndex(getIndex() - 1);
            }
            else if (key == 's') {
                setIndex(getIndex() + 1);
            }

            cursorPosition.X = ConsoleSizeWidth / 2 - 8;
            cursorPosition.Y = ConsoleSizeHeight / 2 - 3 + getIndex() * 2;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
            std::cout << "¢º";

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
            std::cout << getIndex();

            if (key == ' ') {
                switch (getIndex()) {
                case 0:
                    SceneManager::ChangeScene(EScene::Main);
                    while (1) {
                        SceneManager::Update(EScene::Main);
                    }
                    break;
                case 1:
                    SceneManager::ChangeScene(EScene::Info);
                    while (1) {
                        SceneManager::Update(EScene::Info);
                    }
                    break;
                case 2:
                    SceneManager::ChangeScene(EScene::Credit);
                    while (1) {
                        SceneManager::Update(EScene::Credit);
                    }
                    break;
                case 3:
                    exit(0);
                    break;
                }
            }
        }
    }

}
