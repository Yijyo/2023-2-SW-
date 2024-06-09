#include "SceneManager.h"

EScene SceneManager::currentScene = EScene::Intro;

void SceneManager::ChangeScene(EScene scene)
{
	SceneManager::EndScene(SceneManager::currentScene);
	switch (scene)
	{
	case EScene::Intro:
		SceneManager::currentScene = EScene::Intro;
		IntroScene::Start();
		break;
	case EScene::Info:
		SceneManager::currentScene = EScene::Info;
		InfoScene::Start();
		break;
	case EScene::Credit:
		SceneManager::currentScene = EScene::Credit;
		CreditScene::Start();
		break;
	case EScene::Main:
		SceneManager::currentScene = EScene::Main;
		break;
	case EScene::Ending:
		SceneManager::currentScene = EScene::Ending;
		EndingScene::Start();
		break;

	case EScene::Main2:
		SceneManager::currentScene = EScene::Main2;
		MainScene2::Start();
		break;
	
	case EScene::MainScene2Intro :
		SceneManager::currentScene = EScene::MainScene2Intro;
		MainScene2Intro::Start();

	case EScene::BossSceneIntro:
		SceneManager::currentScene = EScene::BossSceneIntro;
		BossSceneIntro::StartBossScene();

	default:
		break;
	}
}

EScene SceneManager::Update(EScene scene) {
	switch (scene)
	{
	case EScene::Intro:
		IntroScene::Update();
		break;
	case EScene::Info:
		InfoScene::Update();
		break;
	case EScene::Credit:
		CreditScene::Update();
		break;
	case EScene::Main:
		MainScene::ismainScene();
		break;
	case EScene::Ending:
		EndingScene::Update();
		break;
	case EScene::Main2:
		MainScene2::isMainScene();
		break;

	case EScene::MainScene2Intro:
		SceneManager::currentScene = EScene::MainScene2Intro;
		MainScene2Intro::Update();


	case EScene::BossSceneIntro:
		SceneManager::currentScene = EScene::BossSceneIntro;
		BossSceneIntro::UpdateBossScene();
	default:
		break;
	}

	return scene;
}

void SceneManager::EndScene(EScene scene) {
	switch (scene)
	{
	case EScene::Intro:
		IntroScene::End();
		break;
	case EScene::Info:
		InfoScene::End();
		break;
	case EScene::Credit:
		CreditScene::End();
		break;
	case EScene::Main:
		IntroScene::End();
		break;
	case EScene::Ending:
		EndingScene::End();
		break;
	case EScene::Main2:
		MainScene2::End();
		break;

	case EScene::MainScene2Intro:
		SceneManager::currentScene = EScene::MainScene2Intro;
		MainScene2Intro::End();

	case EScene::BossSceneIntro:
		SceneManager::currentScene = EScene::BossSceneIntro;
		BossSceneIntro::EndBossScene();
	default:
		break;
	}
}
