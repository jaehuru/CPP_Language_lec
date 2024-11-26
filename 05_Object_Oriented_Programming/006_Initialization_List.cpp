#include <iostream>

using namespace std;

// �ʱ�ȭ�� ���ұ�?
// - ���� ���濡 �߿�
// - ������ �� �ּҰ��� ����Ǿ� ���� ���

// �ʱ�ȭ ���
// - ������ ������
// - �ʱ�ȭ ����Ʈ : ��ó����������
// - C++11 ���� : �ٷ� �ʱ�ȭ�ع�����

// �ʱ�ȭ ����Ʈ
// - ��� ���迡�� ���ϴ� �θ� ������ ȣ���� �� �ʿ�
// - ������ ������ �ʱ�ȭ vs �ʱ�ȭ ����Ʈ
// -- �Ϲ� ������ �� ���� ����
// -- ��� Ÿ���� Ŭ������ ��� ���̰� ����
// -- �����԰� ���ÿ� �ʱ�ȭ�� �ʿ��� ��� (����Ÿ��, const Ÿ��)

class Inventory
{
public:
	Inventory()
	{
		cout << "Inventory()" << endl;
	}

	Inventory(int size)
	{
		cout << "Inventory(int size)" << endl;
	}

	~Inventory()
	{
		cout << "~Inventory()" << endl;
	}

public:

};

class Player
{

};

// Is-A (Knight Is-A Player?) OK ���

// Has-A (Knight Has-A Inventory?) OK ����

class Knight : public Player
{

public:
	Knight() :
	_hp(100),
	_inventory(20),
	_hpRef(_hp),
	_hpConst(_hp)
	{

	}

public:
	int _hp; // ������ ��
	Inventory _inventory;
	int& _hpRef;
	const int _hpConst;
};

int main()
{
	Knight k;
	cout << k._hp << endl;

	return 0;
}

