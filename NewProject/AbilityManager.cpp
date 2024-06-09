#include "AbilityManager.h"

std::vector<ItemSkill> AbilityManager::allSkills = {
    Protecter(' ', "최대체력증가", 99),
    Shoes(' ', "이속  증가", 5),
    NurseMajorBook(' ', "exp량 증가", 5),
    AlcoholSpray(' ', "공격력증가", 5),
    BoosterShot(' ', "공격속도증가", 5),
    KF94Mask(' ', "방어력 증가", 5)
};

std::vector<ItemSkill> AbilityManager::selectedSkills;
int AbilityManager::_selectedNumber;
int AbilityManager::first;
int AbilityManager::second;
int AbilityManager::third;


AbilityManager::AbilityManager()
{

}


void AbilityManager::ShowLevelUpUI() {
    COORD cor;
    _selectedNumber = 0;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN);
    for (int i = 5; i < ConsoleSizeHeight - 5; i++) {
        for (int j = 10; j < ConsoleSizeWidth - 4; j++) {
            cor.X = j;
            cor.Y = i;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
            std::cout << ' ';
        }
        std::cout << std::endl;
    }

    _selectedNumber = 0;

    // 스킬 무작위 선택
    SelectRandomSkill();

    for (int i = 0; i < selectedSkills.size(); i++)
    {
        ShowAbility(ConsoleSizeWidth / 2 - AbilityCardWidth / 2 + (PaddingX + AbilityCardWidth) * (i - 1), ConsoleSizeHeight / 2 - AbilityCardHeight / 2, i);
    }


    cor.X = ConsoleSizeWidth / 2 - 2;
    cor.Y = (ConsoleSizeHeight / 2) - (AbilityCardHeight / 2) - 3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
    std::cout << "레벨업!!!";

    cor.X = ConsoleSizeWidth / 2 - 15;
    cor.Y = (ConsoleSizeHeight / 2) - (AbilityCardHeight / 2) - 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
    std::cout << "A, D  :   선택,      SpaceBar   :    결정";

    while (true)
    {
        bool result = SelectInput();
        if (!result) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
            system("cls");
            return;
        }
    }
}

void AbilityManager::SelectRandomSkill() {
    // 무작위 스킬 선택 로직 구현

    selectedSkills = std::vector<ItemSkill>();
    std::vector<ItemSkill> temp = std::vector<ItemSkill>();

    for (int i = 0; i < allSkills.size(); i++)
    {
        if (allSkills[i].level <= allSkills[i].maxLevel)
        {
            temp.push_back(allSkills[i]);
        }
    }
    allSkills = temp;

    first = 0;
    first = rand() % allSkills.size();
    second = 0;
    second = rand() % allSkills.size();
    third = 0;
    third = rand() % allSkills.size();
    while (1)
    {
        first = rand() % allSkills.size();
        if (allSkills[first].name != allSkills[second].name && allSkills[first].name != allSkills[third].name) {
            break;
        }
    }

    while (1) {
        second = rand() % allSkills.size();
        if (allSkills[first].name != allSkills[second].name && allSkills[second].name != allSkills[third].name) {
            if (!(second == 4 && (BossScene::_player.numberOfStage == 3 || MainScene2::_player.numberOfStage == 2))) {
                break;
            }

        }
    }

    while (1) {
        third = rand() % allSkills.size();
        if (allSkills[third].name != allSkills[second].name && allSkills[first].name != allSkills[third].name) {
            if (!(third == 4 && (BossScene::_player.numberOfStage == 3 || MainScene2::_player.numberOfStage == 2))) {
                break;
            }
        }
    }

    selectedSkills.push_back(allSkills[first]);
    selectedSkills.push_back(allSkills[second]);
    selectedSkills.push_back(allSkills[third]);
}

void AbilityManager::ShowAbility(int cursorX, int cursorY, int index) {
    COORD cor;
    //cursorX += AbilityCardOffsetX;
    int tmp_cur = cursorX + AbilityCardOffsetX;

    cor.X = tmp_cur;
    cor.Y = cursorY + AbilityCardHeight - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
    for (int i = 0; i <= AbilityCardWidth; i++) {
        std::cout << "=";
    }



    Skill selectedSkill = selectedSkills[index];

    cor.X = tmp_cur;
    cor.Y = cursorY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
    for (int i = 0; i <= AbilityCardWidth; i++)
    {
        std::cout << "=";
    }


    for (int i = 0; i < AbilityCardHeight - 2; i++)
    {
        cursorY++;
        cor.X = tmp_cur;
        cor.Y = cursorY;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
        std::cout << "|";

        cor.X = tmp_cur + AbilityCardWidth;
        cor.Y = cursorY;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
        std::cout << "|";

        // 이미지
        if (i == 3)
        {

            cor.X = tmp_cur + AbilityCardWidth / 2;
            cor.Y = cursorY;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
            std::cout << selectedSkill.shape;
        }

        // 이름
        if (i == 5)
        {
            cor.X = tmp_cur + AbilityCardWidth / 2 - 3;
            cor.Y = cursorY;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
            std::cout << (selectedSkill.name);
        }

        // 설명
        if (i == 8)
        {
            cor.X = tmp_cur + AbilityCardWidth / 2;
            cor.Y = cursorY;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
            //std::cout << "레벨 : " + to_string(selectedSkill.level);
        }
    }

    cor.X = tmp_cur;
    cor.Y = cursorY + 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

bool AbilityManager::SelectInput() {
    COORD cor;
    int key;

    for (int i = 0; i < 20; i++)
    {
        if (_kbhit() != 0)
        {
            key = _getch();
            // 입력 처리 로직 구현
            if (key == 'A' || key == 'a') {
                cor.X = ConsoleSizeWidth / 2 + (PaddingX + AbilityCardWidth) * (_selectedNumber - 1) + AbilityCardOffsetX;
                cor.Y = ConsoleSizeHeight / 2 + AbilityCardHeight / 2 + 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
                std::cout << "  ";
                for (int i = ConsoleSizeWidth / 2 + 22; i < ConsoleSizeWidth - 6; i++)
                {
                    cor.X = i;
                    cor.Y = ConsoleSizeHeight / 2 - 5;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
                    std::cout << "  ";

                    cor.X = i;
                    cor.Y = ConsoleSizeHeight / 2 - 4;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
                    std::cout << "  ";
                }
                _selectedNumber--;
                _selectedNumber = Utility::Clamp(_selectedNumber, 0, 2);
            }

            if (key == 'D' || key == 'd') {
                cor.X = ConsoleSizeWidth / 2 + (PaddingX + AbilityCardWidth) * (_selectedNumber - 1) + AbilityCardOffsetX;
                cor.Y = ConsoleSizeHeight / 2 + AbilityCardHeight / 2 + 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
                std::cout << "  ";
                for (int i = ConsoleSizeWidth / 2 + 22; i < ConsoleSizeWidth - 6; i++)
                {
                    cor.X = i;
                    cor.Y = ConsoleSizeHeight / 2 - 5;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
                    std::cout << "  ";

                    cor.X = i;
                    cor.Y = ConsoleSizeHeight / 2 - 4;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
                    std::cout << "  ";
                }
                _selectedNumber++;
                _selectedNumber = Utility::Clamp(_selectedNumber, 0, 2);
            }


            if (key == ' ') {
                // 선택
                if (_selectedNumber == 0) {
                    selectedSkills[0].UpdateLevel();
                    if (first == 0) {
                        Protecter::Use();
                    }
                    else if (first == 1) {
                        Shoes::Use();
                    }
                    else if (first == 2) {
                        NurseMajorBook::Use();
                    }
                    else if (first == 3) {
                        AlcoholSpray::Use();
                    }
                    else if (first == 4) {
                        BoosterShot::Use();
                    }
                    else {
                        KF94Mask::Use();
                    }
                }
                else if (_selectedNumber == 1) {
                    selectedSkills[1].UpdateLevel();
                    if (second == 0) {
                        Protecter::Use();
                    }
                    else if (second == 1) {
                        Shoes::Use();
                    }
                    else if (second == 2) {
                        NurseMajorBook::Use();
                    }
                    else if (second == 3) {
                        AlcoholSpray::Use();
                    }
                    else if (first == 4) {
                        BoosterShot::Use();
                    }
                    else {
                        KF94Mask::Use();
                    }
                }
                else if (_selectedNumber == 2) {
                    selectedSkills[2].UpdateLevel();
                    if (third == 0) {
                        Protecter::Use();
                    }
                    else if (third == 1) {
                        Shoes::Use();
                    }
                    else if (third == 2) {
                        NurseMajorBook::Use();
                    }
                    else if (third == 3) {
                        AlcoholSpray::Use();
                    }
                    else if (third == 4) {
                        BoosterShot::Use();
                    }
                    else {
                        KF94Mask::Use();
                    }
                }

                return false;
            }


            cor.X = ConsoleSizeWidth / 2 + (PaddingX + AbilityCardWidth) * (_selectedNumber - 1) + AbilityCardOffsetX;
            cor.Y = ConsoleSizeHeight / 2 + AbilityCardHeight / 2 + 2;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
            std::cout << "▲";


            cor.X = ConsoleSizeWidth / 2 + 22;
            cor.Y = ConsoleSizeHeight / 2 - 5;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
            std::cout << selectedSkills[_selectedNumber].explanation;

            if (selectedSkills[_selectedNumber].level >= 1) {
                cor.X = ConsoleSizeWidth / 2 + 22;
                cor.Y = ConsoleSizeHeight / 2 - 4;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
                std::cout << selectedSkills[_selectedNumber].levelUpexplanation;
            }


            return true;
        }
    }
}