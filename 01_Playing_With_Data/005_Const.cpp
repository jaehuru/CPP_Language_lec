#include <iostream>

using namespace std;

// const

// 한번 정해지면 절대 바뀌지 않을 값들
// constant의 약자인 const를 붙임 (변수를 상수화 한다고 함)
// const를 붙였으면 초기값을 반드시 지정해야 함

// 전역 변수

// [데이터 영역]
// .data
int a = 2;
// .bss (초기값이 없는 경우)
int b;
// .rodata (읽기 전용 데이터)
const char* msg = "Hello World";


int main()
{
	// const도 바뀌지 않는 읽기 전용?
	// 컴파일러 마음대로
	const int AIR = 0;
	const int STUN = 1;
	const int POLYMORPH = 2;
	const int INVINCIBLE = 3;


	return 0;
}