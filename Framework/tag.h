#pragma once

//GameObject���� ����ϴ� Tag enum�Դϴ�.
//���ӿ�����Ʈ�� �±׸� �޾� �ݴϴ�.
//Tag::basic �̷� ������ ����մϴ�.
//�ڼ��� ������ C++ namespace, C++ enum ���۸� �Ͻðų� ������ ���� �ּ���.
//�浹 ó�� ���� �� �� ����ϸ� ���մϴ�.
namespace Tag {

	enum Tag {
		basic = 0,
		Player,
		Bullet,
		Enemy,
		System
	};
}