#include <iostream>

using namespace std;

// ��ü����

// ������ + ����
// ��ü���� = ��ü
// ��ü��? �÷��̾�, ���� ���

// Knight�� ����
// - �Ӽ�(������): hp, attack, y, x, ...
// - ���(����): Move, Attack, Die
// class�� ������ ���赵

class Knight
{
public:
	// ��� �Լ� ����
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		hp = 0;
		cout << "Die" << endl;
	}

public:
	// ��� ����
	int hp;
	int attack;
	int posY;
	int posX;
};

void Knight::Move(int y, int x)
{
	posY = y;
	posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << attack << endl;
}

// instantiate ��ü�� �����!

int main()
{
	Knight k1;
	k1.hp = 100;
	k1.attack = 10;
	k1.posY = 0;
	k1.posX = 0;

	Knight k2;
	k1.hp = 90;
	k1.attack = 5;
	k1.posY = 1;
	k1.posX = 1;
	k1.Move(2, 2);

	return 0;
}