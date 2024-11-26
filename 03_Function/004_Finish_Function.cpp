#include <iostream>

using namespace std;

// 함수 마무리

// 오버로딩 (중복 정의 : 함수 이름의 재사용)
// - 매개변수 갯수가 다르거나
// - 매개변수 타입이 다르거나 (순서가 다른걸 포함)
int Add(int a, int b)
{
	int sum = a + b;
	return sum;
}

int Add(int a)
{
	int sum = a + 1;
	return sum;
}

float Add(float a, float b)
{
	float sum = a + b;
	return sum;
}

// 기본 인자값
void SetPlayerInfo(int hp, int mp, int attack, int guild_ID = 0) // 단 맨 마지막만 기본값 설정이 가능
{

}

// 스택 오버플로우
int Factorial(int n)
{
	if (n <= 1)
		return 1;
	return n * Factorial(n - 1);
}

int main()
{
	// int result = Add(1.5f, 2.1f); // 데이터 손실이 될 수 있다고 경고를 줌.
	float result = Add(1.5f, 2.1f); // 데이터 손실이 될 수 있다고 경고를 줌.

	cout << result << endl;

	SetPlayerInfo(100, 40, 10); // 기본 값을 설정해줬을때

	int n = Factorial(1000000); // 스택 오버플로우

	cout << n << endl;

	return 0;
}