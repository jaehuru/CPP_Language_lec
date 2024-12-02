#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// override, final
// �����ε�(overloading) : �Լ� �̸��� ����

class Creature
{
public:
	virtual void Attack()
	{
		cout << "Creature" << endl;
	}
};

class Player : public Creature
{
public:
	virtual void Attack() override
	{
		cout << "Player!" << endl;
	}
};

class Knight : public Player
{
public:
	// ������(override)
	virtual void Attack() override // �����Ǹ� �Ҷ��� override�� �� �ٿ�����!
	{
		cout << "Knight!" << endl;
	}

private:
	int _stamina = 100;
};



int main()
{
	Player* c = new Knight();

	c->Attack();

	return 0;
}