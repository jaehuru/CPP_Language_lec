#include <iostream>

using namespace std;

// 템플릿 기초

class Knight
{
public:
	// ...

public:
	int _hp = 100;
};


template<typename T> // 컴파일 과정에서 함수틀을 찍어냄
// template<class T> // SAME 취향차이
void Print(T a)
{
	cout << a << endl;
}

// 템플릿 특수화
template<>
void Print(Knight a)
{
	cout << "Knight !!!!!" << endl;
	cout << a._hp << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

// 연산자 오버로딩 (전역함수 버전)
ostream& operator<<(ostream& os, const Knight& k)
{
	os << k._hp;
	return os;
}

int main()
{
	// 템플릿 : 함수나 클래스를 찍어내는 틀
	// 1) 함수 템플릿
	// 2) 클래스 템플릿

	Print<int>(50);
	Print(50.345f);
	Print(50.12334);
	Print("Hello World");

	Print("Hello", 100);

	int result1 = Add<int>(1, 5);
	float result2 = Add(0.2f, 0.5f);

	Knight k1;
	Print(k1);

	return 0;
}