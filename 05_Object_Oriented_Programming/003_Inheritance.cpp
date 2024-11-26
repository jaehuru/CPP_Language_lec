#include <iostream>

using namespace std;

// ��ü���� (OOP: Object Oriented Programming)
// - ��Ӽ�
// - ���м�
// - ������

// �޸�
// [ Knight ]
// [ [ Player ] ]
// ���(Inheritance) ? �θ� -> �ڽĿ��� ������

// ������(N) / �Ҹ���(1)
// �����ڴ� ź���� ����ؼ� ȣ��Ǵ� �Լ�?
// -Knight�� �����ϸ� -> Player�� ������? Knight�� ������?
// -> �ַθ��� ���� ! �׳� �Ѵ� ȣ���ع���

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
		cout << "Player() �⺻ ������ ȣ��" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player(int hp) ������ ȣ��" << endl;
	}

	~Player()
	{
		cout << "~Player() �Ҹ��� ȣ��" << endl;
	}

	void Move() { cout << "Player Move ȣ��" << endl; }
	void Attack() { cout << "Player Attack ȣ��" << endl; }
	void Die() { cout << "Player Die ȣ��" << endl; }

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
		��ó�� ����
		-���⼭ Plyer() �����ڸ� ȣ��
		*/
	{
		_stamina = 0;
		cout << "Knight() �⺻ ������ ȣ��" << endl;
	}

	Knight(int stamina) :
		Player(100)
	{
		_stamina = stamina;
		cout << "Knight(int stamina) ������ ȣ��" << endl;
	}

	~Knight()
	{
		cout << "~Knight() �Ҹ��� ȣ��" << endl;
	}

	/*
	��ó�� ����
	-���⼭ ~Plyer() �Ҹ��ڸ� ȣ��
	*/

	// ������ : �θ���� ������ �ź��ϰ� ���ο� �̸����� ����

	void Move() { cout << "Knight Move ȣ��" << endl; }

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

	// k.Player::Move(); �Ⱦ� ������ ����

	k.Attack();

	return 0;
}