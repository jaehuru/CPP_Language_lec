#include <iostream>

using namespace std;

// 데이터 연산자

int a = 1;
int b = 2;

int hp;

bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

bool test;
bool isInvincible = true;

int main()
{
#pragma region 산술 연산

	// 산술 연산자
	// 대입 연산

	// a 에 b 를 대입하고 b를 반환하라
	// -> b라는 바구니 안에 있는 값을, a라는 바구니 안에다 복사
	a = b;


	// 사칙 연산
	a = b + 3; // 덧셈 add
	a = b - 3; // 뺄셈 sub
	a = b * 3; // 곱셈 mul
	a = b / 3; // 나눗셈 div
	a = b % 3; // 나머지 div

	a += 3; // a = a + 3;
	a -= 3;
	a *= 3;
	a /= 3;
	a %= 3;

	// 증감 연산자
	a++; // a = a + 1;
	++a;
	a--;
	--a;

	b = a++; // b = a -> a 를 1 증가
	b = ++a; // a를 1증가 -> b = a

#pragma endregion

#pragma region 비교 연산

	// a == b : a 와 b의 값이 같은가?
	// 같으면 1, 다르면 0
	isSame = (a == b);

	// a != b : a 와 b의 값이 다른가?
	// 다르면 1, 같으면 0
	isDifferent = (a != b);

	// a > b : a가 b보다 값이 큰가?
	// a >= b : a가 b보다 값이 크거나 같은가?
	// 크면 1, 아니면 0
	isGreater = (a > b);

	// a < b : a가 b보다 값이 작은가?
	// a <= b : a가 b보다 값이 작거나 같은가?
	// 작으면 1, 같으면 0
	isSmaller = (a < b);

#pragma endregion

#pragma region 논리 연산

	// ! not
	// 0이면 1, 그외 0
	test = !isSame; // 사실상 isDifferent의 의미

	// && and
	// a && b -> 둘다 1이면 1, 그 외 0
	test = (hp <= 0 && isInvincible == false); // 죽음

	// || or
	test = (hp > 0 || isInvincible == true); // 안죽음

#pragma endregion

#pragma region 비트 연산

	// 언제 필요한가?
	// 비트 단위의 조작이 필요할때
	// - 대표적으로 bitFlag

	// ~ bitwise not
	// 단일 숫자의 모든 비트를 대상으로 0은 1, 1은 0으로 뒤바꿈

	// & bitwise and
	// 두 숫자의 모든 비트 쌍을 대상으로 and를 한다

	// | bitwise or
	// 두 숫자의 모든 비트 쌍을 대상으로 or를 한다

	// ^ bitwise xor
	// 두 숫자의 모든 비트 쌍을 대상으로 xor을 한다

	// << 비트 좌측 이동
	// 비트열을 N만큼 왼쪽으로 이동
	// 왼쪽의 넘치는 N개의 비트는 버림. 새로 생성되는 N개의 비트는 0.
	// *2를 할 때 자주 보이는 패턴

	// << 비트 우측 이동
	// 비트열을 N만큼 오른쪽으로 이동
	// 오른쪽의 넘치는 N개의 비트는 버림.
	// 왼쪽 생성되는 N개의 비트는
	// - 부호 비트가 존재 할 경우 부호 비트를 따라감 (부호있는 정수라면 이 부분을 유의)
	// - 아니면 0

#pragma endregion

	return 0;
}