#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Bullet.h"
#include "Scene.h"
#include "EndingScene.h"
#include "ScoreManager.h"


//�������Դϴ�.
Player::Player()
	:GameObject(L"resources/Player.png"),
	moveSpeed(300.0f), timer(0.0f), delay(3.0f)
{
	//�±׸� �����մϴ�.
	tag = Tag::Player;

	//�Ѿ��� �߻��� Gun ������Ʈ�� �߰��մϴ�.
	//�� ������Ʈ���� Shoot �Լ��� �����Ͽ����ϴ�.
	gun = new Gun(0.5f, 1000.0f, 3, 0.1f * PI);
	
	//�浹ü�� �߰��մϴ�.
	col = new AABBCollider(this, renderer);
	//�浹ü�� Scene�� Push�մϴ�.
	//�浹ü�̱� ������ �浹 �˻縦 Scnee���� ����� �մϴ�.
	Scene::PushOnCurrentScene(col);

	//SoundEvent: �Ҹ� ����� ���� ��ü�Դϴ�.
	//se�� �����Ҵ��ϰ�, LoadFile�� ���� ���� ��ü�� �����;� �մϴ�.
	//�ٵ� ��� ���� ���带 ���� �������� �ƴ϶� ���� ���������� ����
	se = new SoundEvent();
	se->LoadFile(L"resources/laser.mp3");

	bgm = new SoundEvent();
	bgm->LoadFile(L"resources/test.wav");
	//Play �Լ��� �뷡 ����� �����մϴ�.
	bgm->Play();
}
Player::~Player()
{
	//�浹ü, soundevent�� �ݵ�� ���� �� �����ؾ� �մϴ�.
	//�ݶ��̴��� Scene���� ���� ������ ���س����
	SAFE_DELETE(col);
	SAFE_DELETE(se);
	SAFE_DELETE(bgm);

	//gun�� GameObject�ν� Scene�� ��ϵ��� �ʾұ� ������
	//�츮�� ���� �������־�� �մϴ�.
	SAFE_DELETE(gun);
}
void Player::Update() {
	//�� ������ ȣ��
	Move();
	Shoot();
	CollisionTimer();
}

void Player::Move()
{
	//�������� ���
	Vector2 input(0.0f, 0.0f);
	if (InputManager::GetKeyState('S'))
	{
		input.y -= 1.0f;
	}
	if (InputManager::GetKeyState('D'))
	{
		input.x += 1.0f;
	}
	if (InputManager::GetKeyState('W'))
	{
		input.y += 1.0f;
	}
	if (InputManager::GetKeyState('A'))
	{
		input.x -= 1.0f;
	}
	if (input.x!=0.0f||input.y!=0.0f)
	{
		input = input.normalized();
		transform->position.x += moveSpeed * input.x * TimeManager::GetDeltaTime();
		transform->position.y += moveSpeed * input.y * TimeManager::GetDeltaTime();
	}
}

void Player::Shoot()
{
	//�Ѿ� �߻縦 ����մϴ�.
	//gun�� GameObject�� �ƴ� �׳� Ŭ�����̹Ƿ� Update�Լ��� ���� ȣ�����ݴϴ�.
	gun->UpdateDelay();

	//���콺 ������ ����մϴ�.
	float angle = ComputeMouseAngle();

	//��ư�� ���ȴٸ� �Ѿ��� �߻��մϴ�.
	if (InputManager::GetKeyDown(VK_LBUTTON))
	{
		//�Ҹ��� ����մϴ�.
		se->Stop();
		se->Play();
		//�Ѿ��� �����մϴ�.
		gun->Shoot(transform->position, angle);
	}
	//���콺 �������� �ٶ󺸰� �մϴ�.
	transform->rotatingAngle = angle;
}


//���콺 �������� ������ ����մϴ�.
float Player::ComputeMouseAngle()
{
	//InputManger::GetMouseX,Y: ���콺 ��ġ�� �޾ƿɴϴ�.
	Vector2 mouse(
		(float)InputManager::GetMouseX(),
		(float)InputManager::GetMouseY()
	);

	//ScreenPosition���� �־����� ���콺 ��ġ�� World��ǥ�� ��ȯ�մϴ�.
	Vector2 mouseInWorld = Camera::ScreenPositionToWorld(mouse);

	//������ ����մϴ�.
	return atan2f(
		mouseInWorld.y - transform->position.y,
		mouseInWorld.x - transform->position.x);
}

//OnCollision: �浹 ������ ȣ��˴ϴ�.
void Player::OnCollision(GameObject* other)
{
	//���� �浹�Ͽ��� ��� �����մϴ�.
	//�浹 �� ��� delay�� �־� ���� �ð��� ����ϴ�.
	if (timer > delay && other->tag == Tag::Enemy)
	{
		hp -= 1;
		std::cout << "ü���� 1 �޾ҽ��ϴ�. ����" << hp << "����\n";
		timer = 0.0f;
	}
	if (hp == 0)
	{
		std::cout << "���� ����";
		Scene::ChangeScene(new EndingScene(ScoreManager::instance->score));
	}
}

//�浹 �� ��� ���� �ð��� �ݴϴ�.
//�ٷ� ���� OnCollision���� timer���� �����˴ϴ�.
//�� �Լ� ��ü�� Update���� �� ������ ����˴ϴ�.
void Player::CollisionTimer()
{
	if (timer <= delay)
	{
		timer += TimeManager::GetDeltaTime();
		renderer->alpha = 0.5f;
	}
	else
	{
		renderer->alpha = 1.0f;
	}
}

