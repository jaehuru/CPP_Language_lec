#include <iostream>

using namespace std;

// 지역 변수와 값 전달

// 전역 변수
// 참고) 초기화 여부, const 등 .rodata .data .bss
int globalValue = 0;


void IncreaseHp(int hp) // main 지역변수 자체로 받은게 아니라 다른 hp 이다
{
	hp = hp + 1; // 결국 main 지역변수를 더해준게 아니라 이 함수자체 매개변수를 더하기만 한것
	// 이 함수의 지역변수는 결국 hp = 2 가 되고 아무런 쓸모가 없다. !매우 중요
}

// [매개변수][RET][지역변수 (hp = 1)] [매개변수 (다른 hp = 1)][RET][지역변수 (hp = 2)]
int main()
{
	// 지역 변수
	int localValue = 0;
	int hp = 1;

	IncreaseHp(hp);

	cout << "hp값은? " << hp << endl; // 어? 왜 안바꼈지?

	return 0;
}