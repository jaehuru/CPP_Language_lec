#include <iostream>

using namespace std;

// 메모리 오염

int& TestRef()
{
	int a = 1;
	return a;
}

int* TestPointer()
{
	int a = 1;
	return &a;
}

void TestWrong(int* ptr)
{
	int a[100] = { };
	a[99] = 0xAAAAAAAA;
	*ptr = 0x12341234;
}

int main()
{
	// 주소를 담는 바구니
	// 진퉁은 저~ 멀리 어딘가에 있음
	// p는 단지 그 곳으로 워프하는 포탈

	int* p;

	// 진짜배기! 원조 데이터
	// 닭장처럼 데이터의 묶음 (엄청 많고 거대함)

	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// [배열의 이름]은 배열의 시작 주소값을 가르키는 TYPE*형 포인터로 변환 가능!

	p = arr;

	// [TYPE형 1차원 배열]과 [TYPE*형 포인터]는 완전히 호환이 된다

	cout << p[0] << endl;
	cout << arr[0] << endl;
	cout << p[5] << endl;
	cout << arr[5] << endl;
	cout << *p << endl; // p[0]
	cout << *arr << endl; // arr[0]
	cout << *(p + 3) << endl;
	cout << *(arr + 3) << endl;

	// 지옥을 보여드리겠습니다. (2차원 배열 vs 다중 포인터)

	int arr2[2][2] = { {1, 2}, {3, 4} };

	// pp[ 주소1 ]
	// 주소1 [ 주소2 ]
	// 주소2[ ]


	// 00000001[ ] << 메모리값의 주소값으로 가기 때문에 예외처리가 남
	// 주소1 [ 00000001 ] 주소값이 메모리값
	// pp[ 주소1 ]

	// int** pp = (int**)arr2;

	// cout << (**pp) << endl;

	// [ 주소 ]
	// [ 1 ][ 2 ]

	int(*p2)[2] = arr2;

	cout << (*p2)[0] << endl;
	cout << (*p2)[1] << endl;
	cout << (*(p2 + 1))[0] << endl;
	cout << (*(p2 + 1))[1] << endl;
	cout << p2[0][0] << endl;
	cout << p2[0][1] << endl;
	cout << p2[1][0] << endl;
	cout << p2[1][1] << endl;

	// [매개변수][RET][지역변수] [매개변수][RET][지역변수(a)]

	int* pointer = TestPointer();
	TestWrong(pointer);

	return 0;
}