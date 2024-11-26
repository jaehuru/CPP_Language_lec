#include <iostream>

using namespace std;

// 호출 스택

// 빌드가 되지 않는다... 
// 그 이유는? 컴파일할 때 위에서부터 분석을 하기 때문에 Func1 함수에서 Func2를 모름;

// 먼저 함수를 선언해주면 해결! (주석을 풀면 해결됨)
//void Func1();
//void Func2(int a, int b);
//void Func3(float a);

// 함수가 호출되는 순서를 보여주는것이 호출 스택
// 결론은 호출스택은 디버그할때 유용하다!

void Func1()
{
	cout << "Func1" << endl;

	Func2(1, 2);
}

void Func2(int a, int b)
{
	cout << "Func2" << endl;

	Func3(10.f);
}

void Func3(float a)
{
	cout << "Func3" << endl;
}

int main()
{
	cout << "Main" << endl;
	Func1();
	

	return 0;
}