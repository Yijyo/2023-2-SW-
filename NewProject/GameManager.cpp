#include "GameManager.h"

void GameManager::Init() 
{
	SetConsoleTitle(TEXT("Escape From Pandemic"));

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hConsole, &cursorInfo);

	COORD size = { ConsoleSizeWidth, ConsoleSizeHeight };
	SetConsoleScreenBufferSize(hConsole, size);
}

void GameManager::Start() 
{
	Init();
	SceneManager::currentScene = EScene::Intro;
	SceneManager::ChangeScene(SceneManager::currentScene);
}

void GameManager::Update() 
{
	while (true) 
	{
		Init();
		SceneManager::Update(SceneManager::currentScene);
	}
}

