#pragma once
#include "TitleScece.h"

class SceneManger
{
public:
	SceneManger() = delete;
	~SceneManger() = delete;
	SceneManger(const SceneManger&) = delete;
	SceneManger& operator=(const SceneManger&) = delete;

	static void Init() { _currentScene->Init(); }
	static void Update() { _currentScene->Update(); }
	static void Render() { _currentScene->Render(); }
	static void Release() { _currentScene->Release(); }

	static bool IsSetnextScene() { return _nextScene != nullptr; }
	static void SetNextScene()
	{
		static int sceneIndex;
		static const int MAX_SCENE = 2;
		​
			sceneIndex = (sceneIndex + 1) % MAX_SCENE;
		switch (sceneIndex)
		{
		case 0:
			_nextScene = new TitleScene();
			break;
		case 1:
			_nextScene = new DrunkenScene();
			break;
		}
	}
	static void Change()
	{
		if (_nextScene == nullptr)
		{
			return;
		}
		_currentScene->Release();
		delete _currentScene;
		_currentScene = _nextScene;
		_currentScene->Init();
		_nextScene = nullptr;
	}
private:
	static Scene* _currentScene;
	static Scene* _nextScene;
};

