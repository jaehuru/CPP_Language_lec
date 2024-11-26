#include <iostream>

using namespace std;

// 포인터 연산

// 1) 주소 연산자 (&)
// 2) 산술 연산자 (+ -)
// 3) 간접 연산자 (*)
// 4) 간접 멤버 연산자 (->)

struct PlayerInfo
{
	int hp;
	int attack;
};

int main()
{
	int number = 1;

	// 1) 주소 연산자 (&)
	// - 해당 변수의 주소를 알려주세요~
	// - 더 정확히 말하면 해당 변수 타입에 따라서 TYPE* 반환
	int* pointer = &number;

	// 2) 산술 연산자 (+ -)

	number += 1; // 1 증가했다 (!)


	pointer += 1; // 4가 증가했다 (?) 그 이유는 [!]
	// int* : 주소를 따라가면 int(4바이트)가 있다고 가정해라!

	// [!] 포인터에서 +나 -등 산술 연산으로 1을 더하거나 빼면,
	// 그 숫자를 연산하라는 의미가 아니다.
	// 한번에 TYPE의 크기만큼을 이동하라는 의미!
	// 즉, 1을 더하면 = 바구니 1개 이동시켜라 이런 뜻!

	// 3) 간접연산자 (*)
	// - 포탈을 타고 해당 주소로 슝~! 이동
	number = 3;
	*pointer = 3;

	// 4) 간접 멤버 연산자 (->)
	// * 간접 연산자와 . 구조체의 특정 멤버를 다룰 때 사용 (어셈블리로 까보면 . 사실상 그냥 덧셈)
	// -> 는 * 와 . 한방에!
	PlayerInfo player;
	player.hp = 100;
	player.attack = 10;

	PlayerInfo* playerPtr = &player;
	playerPtr->hp = 100; // (*playerPtr).hp = 100;
	playerPtr->attack = 100;

	return 0;
}