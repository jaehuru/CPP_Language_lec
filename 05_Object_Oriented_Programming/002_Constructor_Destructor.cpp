#include <iostream>

using namespace std;

// [������(Constructor)�� �Ҹ���(Destructor)]
// Ŭ������ '�Ҽ�'�� �Լ����� ��� �Լ���� ��
// �� �߿��� ������ Ư���� �Լ� 2���� �ִµ�, �ٷ� [����]�� [��]�� �˸��� �Լ���

// - ����(ź��) -> ������ (������ ���簡��)
// - ��(�Ҹ�) -> �Ҹ��� (���� 1��)

// [�Ͻ���(Implicit) ������]
// �����ڸ� ��������� ������ ������, �ƹ� ���ڵ� ���� �ʴ� [�⺻ ������]�� �����Ϸ��� ���� �ڵ����� �������.
// -> �׷��� �츮�� �����(Explicit)���� �ƹ� ������ �ϳ� �����,

// �ڵ����� ��������� [�⺻ ������]�� ���̻� ��������� ����!
// class�� ������ ���赵

class Knight
{
public:
	// [1] �⺻ ������ (���ڰ� ����)
	Knight()
	{
		cout << "Knight() �⺻ ������ ȣ��" << endl;
		_hp = 100;
		_attack = 10;
		_posY = 0;
		_posX = 0;
	}

	// [2] ���� ������ (�ڱ� �ڽ��� Ŭ���� ���� Ÿ���� ���ڷ� ����)
	// (�Ϲ������� '�Ȱ���' �����͸� ���� ��ü�� �����Ǳ� ����Ѵ�

	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_attack = knight._attack;
		_posY = knight._posY;
		_posX = knight._posX;
	}

	// [3] ��Ÿ ������
	// �� �߿��� ���ڸ� 1���� �޴� [��Ÿ ������]�� [Ÿ�� ��ȯ ������]��� �θ��⵵ ��

	// ������� �뵵�θ� ����� ��!

	explicit Knight(int hp)
	{
		cout << "Knight() ��Ÿ ������ ȣ��" << endl;
		_hp = hp;
		_attack = 10;
		_posY = 0;
		_posX = 0;
	}

	Knight(int hp, int attack, int posY, int posX)
	{
		_hp = hp;
		_attack = attack;
		_posY = posY;
		_posX = posX;
	}

	// �Ҹ���

	~Knight()
	{
		cout << "~Knight() �Ҹ��� ȣ��" << endl;
	}

	// ��� �Լ� ����
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		_hp = 0;
		cout << "Die" << endl;
	}

public:
	// ��� ����
	int _hp;
	int _attack;
	int _posY;
	int _posX;

};

void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

void HelloKnight(Knight k)
{
	cout << "Hello Knight" << endl;
}

// instantiate ��ü�� �����!

int main()
{
	Knight k1(100, 10, 0, 0);
	k1._hp = 100;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	Knight k2(k1); // ���� ������
	Knight k3 = k1; // ���� ������
	Knight k4; // �⺻ ������

	k4 = k1;
	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	// �Ͻ��� ����ȯ -> �����Ϸ��� �˾Ƽ� �ٲ�ġ��

	int num = 1;
	float f = (float)num; // ����� < �츮�� �ڵ�� num�� float �ٱ��Ͽ� ������� �ֹ��ϰ� ����
	double d = num; // �Ͻ��� << ���� ���ߴµ� �����Ϸ��� �˾Ƽ� ó���ϰ� ����

	Knight k5;
	k5 = (Knight)1;

	HelloKnight((Knight)5);

	return 0;

}