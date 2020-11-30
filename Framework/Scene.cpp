#include "stdafx.h"
#include "Scene.h"
#include "Framework.h"
#include "GameObject.h"

Scene* Scene::currentScene = nullptr;
Scene* Scene::nextScene = nullptr;

Scene::Scene(): renderingManager(nullptr), collisionManager(nullptr), camera(nullptr), d2dApp(nullptr), subScreen(nullptr)
{
}

Scene::~Scene()
{
	for (auto& i : gameObjectList)
	{
		SAFE_DELETE(i);
	}
	gameObjectList.clear();
	renderableList.clear();	
	SAFE_DELETE(renderingManager);
	SAFE_DELETE(collisionManager);
}

void Scene::SwapScene(D2DApp* d2dApp)
{
	if (!nextScene)
		return;

	SAFE_DELETE(currentScene);
	currentScene = nextScene;
	nextScene = nullptr;

	currentScene->d2dApp = d2dApp;
	currentScene->renderingManager = new RenderingManager(d2dApp);
	currentScene->collisionManager = new CollisionManager();
	currentScene->camera = new Camera();
	currentScene->Push(currentScene->camera);

	currentScene->Initialize();
}

void Scene::ChangeScene(Scene* nextScene)
{
	if (Scene::nextScene)
		SAFE_DELETE(Scene::nextScene);
	Scene::nextScene = nextScene;
}

Scene* Scene::GetCurrentScene()
{
	return Scene::currentScene;
}

GameObject* Scene::PushOnCurrentScene(GameObject* gameObject)
{
	if (currentScene)
		return currentScene->Push(gameObject);
	else
		std::cout << "Scene::PushObject error: ���� ���� �����ϴ�.\n";
	return nullptr;
}

GameObject* Scene::PushUIOnCurrentScene(GameObject* gameObject)
{
	if (currentScene)
		return currentScene->PushUI(gameObject);
	else
		std::cout << "Scene::PushObject error: ���� ���� �����ϴ�.\n";
	return nullptr;
}

AABBCollider* Scene::PushOnCurrentScene(AABBCollider* col)
{
	if (currentScene)
	{
		return currentScene->Push(col);
	}
	else
	{
		std::cout << "Scene::PushObject: ���� ���� �����ϴ�.\n";
	}
	return nullptr;
}

CircleCollider* Scene::PushOnCurrentScene(CircleCollider* col)
{
	if (currentScene)
	{
		return currentScene->Push(col);
	}
	else
	{
		std::cout << "Scene::PushObject: ���� ���� �����ϴ�.\n";
	}
	return nullptr;
}

void Scene::Initialize()
{
	GameObject* g = Push(new GameObject(L"a.png"));
	g->transform->SetPosition(100.0f, 100.0f);
}

void Scene::UpdateGameObjects()
{
	//��� ������Ʈ�� Update�� ����
	for (auto& i : gameObjectList)
		if (i->isActive)
			i->Update();

	//LateUpdate ����
	for (auto& i : gameObjectList)
		if (i->isActive)
			i->LateUpdate();
}

void Scene::UpdatePhysics()
{
	collisionManager->Update();
}

void Scene::DeleteDestroyedObjects()
{
	//���� ��û���� ������Ʈ ����
	auto i = destroyedObjectList.begin();
	while (i != destroyedObjectList.end())
	{
		(*i)->OnDestroy();
		gameObjectList.remove(*i);		//���ӿ�����Ʈ����Ʈ���� ����
		renderableList.remove(*i);		//�������� ����Ʈ���� ����
		uiList.remove(*i);		//�������� ����Ʈ���� ����
		collisionManager->RemoveGameObject(*i);
		GameObject* t = *i;
		SAFE_DELETE(t);				//delete
		destroyedObjectList.remove(*i);
		i = destroyedObjectList.begin();
	}
	destroyedObjectList.clear();
}

void Scene::Render()
{
	renderingManager->BeginRender();

	Vector2 screenSize;
	screenSize.x = WinApp::GetScreenWidthF();
	screenSize.y = WinApp::GetScreenHeightF();
	for (auto& i : renderableList)
	{
		i->renderer->Render(Scene::d2dApp, i->transform,i->renderer->ComputeWorldPosition(screenSize,i->transform,camera->transform->position));
	}

	for (auto& i : uiList)
	{
		i->renderer->Render(Scene::d2dApp, i->transform, i->renderer->ComputeUIPosition(i->transform));
	}

	if (subScreen)
	{
		SubRender();
		subScreen->renderer->Render(Scene::d2dApp, subScreen->transform, subScreen->renderer->ComputeUIPosition(subScreen->transform));
	}

	renderingManager->EndRender();
}

void Scene::SubRender()
{
	if (!subScreen)
	{
		printf("no subscreen\n");
		return;
	}
	
	subScreen->BeginSubRender();

	for (auto& i : renderableList)
	{
		i->renderer->BasicRender(
			subScreen->subRenderTarget,
			i->transform,
			nullptr,
			i->renderer->ComputeWorldPosition(subScreen->subScreenSize, i->transform, subScreen->lookAtPosition));
	}

	subScreen->EndSubRender();
}

D2DApp* Scene::GetD2DApp()
{
	return d2dApp;
}

GameObject* Scene::Push(GameObject* gameObject)
{
	//���� ������Ʈ�� �������
	gameObjectList.push_back(gameObject);
	//�������� �̹����� �������
	//�������� ����Ʈ�� �������
	if (gameObject->renderer->GetInitialized())
	{
		renderableList.push_back(gameObject);
	}
	return gameObject;//���� ���ӿ�����Ʈ�� �״�� ��ȯ
}

GameObject* Scene::PushUI(GameObject* gameObject)
{
	//���� ������Ʈ�� �������
	gameObjectList.push_back(gameObject);
	//�������� �̹����� �������
	//�������� ����Ʈ�� �������
	if (gameObject->renderer->GetInitialized())
	{
		uiList.push_back(gameObject);
	}
	return gameObject;//���� ���ӿ�����Ʈ�� �״�� ��ȯ
}

AABBCollider* Scene::Push(AABBCollider* col)
{
	if (currentScene->collisionManager)
		return currentScene->collisionManager->PushBackCollider(col);
	else
		std::cout << "Scene::PushObject: collisionManager�� �����ϴ�.\n";
	return nullptr;
}

CircleCollider* Scene::Push(CircleCollider* col)
{
	if (currentScene->collisionManager)
		return currentScene->collisionManager->PushBackCollider(col);
	else
		std::cout << "Scene::PushObject: collisionManager�� �����ϴ�.\n";
	return nullptr;
}

void Scene::Destroy(GameObject* o)
{
	//������ ������Ʈ ����Ʈ�� �������
	if (currentScene)
	{
		currentScene->destroyedObjectList.push_back(o);
	}
	else
	{
		std::cout << "Scene::Destroy ���� ���� �����ϴ�.\n";
	}
}

RenderingManager* Scene::GetRenderingManager()
{
	return renderingManager;
}

CollisionManager* Scene::GetCollisionManager()
{
	return collisionManager;
}

Camera* Scene::GetCamera()
{
	return camera;
}
