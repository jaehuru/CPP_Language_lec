#include <iostream>

using namespace std;

// 객체지향 (OOP: Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

// 메모리
// [ Knight ]
// [ [ Player ] ]
// 상속(Inheritance) ? 부모 -> 자식에게 물려줌

// 생성자(N) / 소멸자(1)
// 생성자는 탄생을 기념해서 호출되는 함수?
// -Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 솔로몬의 선택 ! 그냥 둘다 호출해버려

// GameObject
// - Creature
// -- Player, Monster, Npc, Pet
// - Projectile
// -- Arrow, Fireball
// - Env
// Item
// -Weapon
// -- Sword, Bow
// -Armor
// -- Helmet, ...
// -Consumable
// -- ...

class Player
{
public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player() 기본 생성자 호출" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player(int hp) 생성자 호출" << endl;
	}

	~Player()
	{
		cout << "~Player() 소멸자 호출" << endl;
	}

	void Move() { cout << "Player Move 호출" << endl; }
	void Attack() { cout << "Player Attack 호출" << endl; }
	void Die() { cout << "Player Die 호출" << endl; }

public:
	int _hp;
	int _attack;
	int _defence;
};

class Knight : public Player
{

public:
	Knight()
		/*
		선처리 영역
		-여기서 Plyer() 생성자를 호출
		*/
	{
		_stamina = 0;
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	Knight(int stamina) :
		Player(100)
	{
		_stamina = stamina;
		cout << "Knight(int stamina) 생성자 호출" << endl;
	}

	~Knight()
	{
		cout << "~Knight() 소멸자 호출" << endl;
	}

	/*
	후처리 영역
	-여기서 ~Plyer() 소멸자를 호출
	*/

	// 재정의 : 부모님의 유산을 거부하고 새로운 이름으로 만든

	void Move() { cout << "Knight Move 호출" << endl; }

public:
	int _stamina;
};

class Mage : public Player
{
public:

public:
	int _mp;
};

int main()
{
	Knight k(100);

	k._hp = 100;
	k._attack = 10;
	k._defence = 5;

	//k._stamina = 50;

	k.Move();

	// k.Player::Move(); 안씀 문법은 있음

	k.Attack();

	return 0;
}