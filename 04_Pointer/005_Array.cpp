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
	// TYPE 이름[개수];
	// 배열의 크기는 상수여야 함 (VC 컴파일러 기준)

	const int monsterCount = 10;
	Statinfo monsters[monsterCount];

	// 여태껏 변수들의 [이름]은 바구니의 이름었음

	int a = 10;
	int b = a;

	// 그런데 배열은 [이름] 조금 다르게 동작한다
	// Statinfo players[10];
	// players = monsters;
	// 그럼 배열의 이름은 곧 배열의 시작주소
	// 정확히는 시작 위치를 가르키는 TYPE* 포인터

	auto WhoAmI = monsters;

	// Statinfo[ 100, 10, 1 ] Statinfo[ ] Statinfo[ ] Statinfo[ ] Statinfo[ ] Statinfo[ ] ...
	// monster_0[ 주소 ]

	Statinfo* monster_0 = monsters;

	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// 포인터의 덧셈! 바구니 한개씩 이동
	// Statinfo[ ] 주소[ 200,20,2 ] Statinfo[ ] Statinfo[ ] Statinfo[ ] Statinfo[ ] ...
	// monster_1[ 주소 ]

	Statinfo* monster_1 = monsters + 1;

	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// 포인터와 참조는 자유자재로 변환 가능하다
	// Statinfo[ ] Statinfo[ ] 주소[ 300, 30, 3 ] Statinfo[ ] Statinfo[ ] Statinfo[ ] ...
	// monster_2[ 주소 ]

	Statinfo& monster_2 = *(monsters + 2);

	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// [주의] 이거는 완전 다른 의미다
	// Statinfo[ ] Statinfo[ ] 주소[ 내용물 ] Statinfo[ ] Statinfo[ ] Statinfo[ ] ...
	// temp[ 내용물 ]

	Statinfo temp;

	temp = *(monsters + 2);
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4;

	// 자동화

	for (int i = 0; i < 10; i++)
	{
		Statinfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = (i + 1);
	}

	// 가독성이 별루임
	// 인덱스!
	// 배열은 0번 부터 시작
	// *(monsters + i) = monsters[i]

	for (int i = 0; i < 10; i++)
	{
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defence = (i + 1);
	}

	// 배열 초기화 문법 몇가지

	int numbers[5] = {}; // 다 0으로 밀어버린다
	int numbers1[10] = { 1,2,3,4,5 };
	int numbers2[] = { 1,2,3,4,5,6,7,8,9,10 }; // 데이터 개수만큼의 크기에 해당하는 배열로 만들어준다
	char helloStr[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	cout << helloStr << endl;

	return 0;

}