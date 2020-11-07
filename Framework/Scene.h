#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "RenderingManager.h"
#include "CollisionManager.h"

class Scene
{
	friend class Framework;
public:
	Scene();
	virtual ~Scene();

private:
	static D2DApp* d2dApp;
	static Scene* currentScene;
	static Scene* nextScene;
	static void SwapScene(D2DApp* d2dApp);

public:
	static void ChangeScene(Scene* nextScene);
	static Scene* GetCurrentScene();

public:
	std::list<GameObject*> renderableList;
	std::list<GameObject*> gameObjectList;
	std::list<GameObject*> destroyedObjectList;
	RenderingManager* renderingManager;
	CollisionManager* collisionManager;

private:
	virtual void Initialize() = 0;
	void UpdateGameObjects();
	void UpdatePhysics();
	void DeleteDestroyedObjects();
	void Render();

public:
	GameObject* PushBackGameObject(GameObject* gameObject);
	void Destroy(GameObject* o);

public:
	RenderingManager* GetRenderingManager();
	CollisionManager* GetCollisionManager();
};

