#include <iostream>

using namespace std;

// 조건문 분기문
// 데이터를 메모리에 할당하고 가공하는 방법에 대해 알아봄

int main()
{
	int hp = 100;
	int damage = 100;

	hp -= damage;
	bool isDead = (hp <= 0);

	// if = else if - else 
	if (isDead)
		cout << "죽었습니다" << endl;
	else if (hp <= 20)
		cout << "도망갔습니다" << endl;
	else
		cout << "반격했습니다" << endl;

	const int ROCK = 0;
	const int PAPER = 1;
	const int SCISSORS = 2;

	int input = ROCK;
	// switch - case - break

	// 정수 계열만 넣을 수 있다.
	switch (input)
	{
	case ROCK:
		cout << "바위를 냈습니다" << endl;
		break;
	case PAPER:
		cout << "보를 냈습니다" << endl;
		break;
	case SCISSORS:
		cout << "가위를 냈습니다" << endl;
		break;
	}


	return 0;
}