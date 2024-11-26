#include <iostream>

using namespace std;

struct Statinfo
{
	int hp = 0xAAAAAAAA; // +0
	int attack = 0xBBBBBBBB; // +4
	int defence = 0xDDDDDDDD; // +8
};

int main()
{
	// TYPE �̸�[����];
	// �迭�� ũ��� ������� �� (VC �����Ϸ� ����)

	const int monsterCount = 10;
	Statinfo monsters[monsterCount];

	// ���²� �������� [�̸�]�� �ٱ����� �̸�����

	int a = 10;
	int b = a;

	// �׷��� �迭�� [�̸�] ���� �ٸ��� �����Ѵ�
	// Statinfo players[10];
	// players = monsters;
	// �׷� �迭�� �̸��� �� �迭�� �����ּ�
	// ��Ȯ���� ���� ��ġ�� ����Ű�� TYPE* ������

	auto WhoAmI = monsters;

	// Statinfo[ 100, 10, 1 ] Statinfo[ ] Statinfo[ ] Statinfo[ ] Statinfo[ ] Statinfo[ ] ...
	// monster_0[ �ּ� ]

	Statinfo* monster_0 = monsters;

	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// �������� ����! �ٱ��� �Ѱ��� �̵�
	// Statinfo[ ] �ּ�[ 200,20,2 ] Statinfo[ ] Statinfo[ ] Statinfo[ ] Statinfo[ ] ...
	// monster_1[ �ּ� ]

	Statinfo* monster_1 = monsters + 1;

	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// �����Ϳ� ������ ��������� ��ȯ �����ϴ�
	// Statinfo[ ] Statinfo[ ] �ּ�[ 300, 30, 3 ] Statinfo[ ] Statinfo[ ] Statinfo[ ] ...
	// monster_2[ �ּ� ]

	Statinfo& monster_2 = *(monsters + 2);

	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// [����] �̰Ŵ� ���� �ٸ� �ǹ̴�
	// Statinfo[ ] Statinfo[ ] �ּ�[ ���빰 ] Statinfo[ ] Statinfo[ ] Statinfo[ ] ...
	// temp[ ���빰 ]

	Statinfo temp;

	temp = *(monsters + 2);
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4;

	// �ڵ�ȭ

	for (int i = 0; i < 10; i++)
	{
		Statinfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = (i + 1);
	}

	// �������� ������
	// �ε���!
	// �迭�� 0�� ���� ����
	// *(monsters + i) = monsters[i]

	for (int i = 0; i < 10; i++)
	{
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defence = (i + 1);
	}

	// �迭 �ʱ�ȭ ���� ���

	int numbers[5] = {}; // �� 0���� �о������
	int numbers1[10] = { 1,2,3,4,5 };
	int numbers2[] = { 1,2,3,4,5,6,7,8,9,10 }; // ������ ������ŭ�� ũ�⿡ �ش��ϴ� �迭�� ������ش�
	char helloStr[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	cout << helloStr << endl;

	return 0;

}