#include <iostream>

using namespace std;

// 열거형

// 숫자를 지정 안하면 첫 값은 0부터 시작
// 그 다음 값들은 이전 값 +1
enum ENUM_SRP
{
	ENUM_SCISSORS,
	ENUM_ROCK,
	ENUM_PAPER,
};

// #이 붙은거 -> 전처리 지시문
// #include <iostream> 이라는 파일을 찾아서 해당 내용을 전체 복붙!
// 1) 전처리 2) 컴파일 3) 링크
#define DEFINE_SCISSORS 1
#define DEFINE_ROCK 2
#define DEFINE_PAPER 3
#define DEFINE_TEST cout << "Hello World" << endl;

int main()
{
	DEFINE_TEST;

	return 0;
}