#include <iostream>

using namespace std;

// 함수 포인터2

class Knight
{
public:

	// 멤버 함수
	int GetHp(int, int)
	{
		cout << "Gethp()" << endl;
		return _hp;
	}

public:
	int _hp = 100;

};

// typedef 의 진실
// typedef 왼쪽 -> 오른쪽 (커스텀 타입 정의)
typedef int NUMBER;

// 정확히는 왼쪽/오른쪽 기준이 아니라, [선언 문법]에서 typedef을 앞에다 붙이는 쪽

typedef int INTEGER;
typedef int* POINTER;
typedef int (FUNC)(int, int);
typedef int ARRAY[20];

typedef int (*PFUNC)(int, int); // 함수 포인터

typedef int (Knight::*PMEMFUNC)(int, int); // 멤버 함수 포인터

int Test(int, int)
{
	cout << "Test" << endl;
	return 0;
}

int t(int, int)
{
	cout << "t" << endl;
	return 0;
}

int main()
{
	// 함수 포인터
	// 1) 포인터            *
	// 2) 변수의 이름        fn
	// 3) 타입              함수(인자로 int 2개를 받고, int 1개를 반환)
	//int (*fn)(int, int);

	//typedef int(FUNC_TYPE)(int, int);
	//FUNC_TYPE* fn;

	PFUNC fn;

	fn = &Test; // & 생략 가능 ( C언어 호환성 때문 )

	fn(1, 2);
	(*fn)(1, 2);

	// 위 문법으로 [전역 함수 / 정적 함수]만 담을 수 있다 (호출 규약이 동일한 애들)
	// fn = &Knight::GetHp; 불가능

	Test(1, 2);

	Knight k1;
	k1.GetHp(1, 1);

	PMEMFUNC mfn;
	mfn = &Knight::GetHp; // 멤버 함수에는 &붙여야 함
	(k1.*mfn)(1, 1);

	Knight* k2 = new Knight();
	(k2->*mfn)(1, 1);
	delete k2;

	return 0;
}