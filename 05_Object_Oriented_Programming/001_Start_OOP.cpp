#include <iostream>

using namespace std;

// 객체지향

// 데이터 + 가공
// 객체지향 = 객체
// 객체란? 플레이어, 몬스터 등등

// Knight를 설계
// - 속성(데이터): hp, attack, y, x, ...
// - 기능(동작): Move, Attack, Die
// class는 일종의 설계도

class Knight
{
public:
	// 멤버 함수 선언
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		hp = 0;
		cout << "Die" << endl;
	}

public:
	// 멤버 변수
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

// instantiate 객체를 만든다!

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