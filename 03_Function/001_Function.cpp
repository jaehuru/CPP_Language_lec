#include <iostream>

using namespace std;

// 함수 (프로시저, 메소드, 루틴)

/*
input으로 무엇을 받고, output으로 무엇을 뱉을지 정해준다

반환타입 함수이름([인자타입 매개변수])
{
	함수 내용

	return ~~~;
}
*/

// Hello World를 콘솔에 출력하는 함수를 만들어보자!
// input : 없음 / output : 없음
// 타입 : int float double char ~~~ void

void PrintHelloWorld()
{
	cout << "Hello World" << endl;
}

// 정수를 입력(함수) 받아서, 콘솔에 출력하는 함수를 만들어보자
// input : int / output : 없음
void PrintNumber(int number)
{
	cout << "넘겨주신 숫자는 " << number << " 입니다" << endl;
}

int MultiplyBy2(int a)
{
	return a * 2;
}

int MultiplyBy(int a, int b)
{
	return a * b;
}

int main()
{
	int num = MultiplyBy(3, 5);

	PrintNumber(num);

	return 0;
}