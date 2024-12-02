#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// override, final
// 오버로딩(overloading) : 함수 이름의 재사용

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
	// 재정의(override)
	virtual void Attack() override // 재정의를 할때는 override를 꼭 붙여주자!
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