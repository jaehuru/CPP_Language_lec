#include <iostream>

using namespace std;

void Test(int a)
{
	a++;
}

// 배열은 함수 인자로 넘기면, 컴파일러가 알아서 포인터로 치환한다 (char[] -> char*)
// 즉 배열의 내용 전체를 넘긴게 아니라, 시작 주소(포인터)만 넘긴 것

void Test(char a[])
{
	a[0] = 'x';
}

int main()
{
	// .data 주소 [H][e][l][l][o][][W][o][r][l][d][\0]
	// test1[ 주소 ] << 8바이트

	const char* test1 = "Hello World";

	//test1[0] = 'R'; 불가능
	// .data 주소 [H][e][l][l][o][][W][o][r][l][d][\0]
	// [H][e][l][l][o][][W][o][r][l][d][\0] 4바이트씩 운반
	// test2 = 주소

	char test2[] = "Hello World";

	//test2[0] = 'R';
	//cout << test2 << endl;
	// 포인터는 [ 주소를 담는 바구니 ]
	// 배열은 [닭장] 즉, 그 자체로 같은 데이터끼리 붙어있는 '바구니모음'
	// -다만 [배열이름]은 '바구니 모음'의 [ 시작 주소 ]
	// 배열을 함수의 인자로 넘기게 되면?

	int a = 0;

	// [매개변수][RET][지역변수(a=0)][매개변수(a=1)][RET][지역변수]

	Test(a);
	cout << a << endl;

	// 바뀐다!

	Test(test2);
	cout << test2 << endl;

	return 0;

}