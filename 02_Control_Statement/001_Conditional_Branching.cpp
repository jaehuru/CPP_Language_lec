#include <iostream>

using namespace std;

// ���ǹ� �б⹮
// �����͸� �޸𸮿� �Ҵ��ϰ� �����ϴ� ����� ���� �˾ƺ�

int main()
{
	int hp = 100;
	int damage = 100;

	hp -= damage;
	bool isDead = (hp <= 0);

	// if = else if - else 
	if (isDead)
		cout << "�׾����ϴ�" << endl;
	else if (hp <= 20)
		cout << "���������ϴ�" << endl;
	else
		cout << "�ݰ��߽��ϴ�" << endl;

	const int ROCK = 0;
	const int PAPER = 1;
	const int SCISSORS = 2;

	int input = ROCK;
	// switch - case - break

	// ���� �迭�� ���� �� �ִ�.
	switch (input)
	{
	case ROCK:
		cout << "������ �½��ϴ�" << endl;
		break;
	case PAPER:
		cout << "���� �½��ϴ�" << endl;
		break;
	case SCISSORS:
		cout << "������ �½��ϴ�" << endl;
		break;
	}


	return 0;
}