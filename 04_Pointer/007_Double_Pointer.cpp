#include <iostream>

using namespace std;

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}

void SetMessage(const char** a)
{
	*a = "Bye";
}

void SetMessage2(const char*& a)
{
	a = "Wow";
}

int main()
{
	int a = 0;
	SetNumber(&a);

	// cout << a << endl;
	// .rdata Hello주소[H][e][l][l][o][\0]
	// .rdata Bye주소[B][y][e][\0]
	// msg[ Hello주소 ] << 8바이트

	const char* msg = "Hello";

	// [매개변수][RET][지역변수(msg( Hello주소 ))][매개변수(a( Bye주소 ))][RET][지역변수]

	SetMessage(msg);

	// cout << msg << endl; // Hello? Bye?
	// 주소2 [ ] << 1바이트
	// 주소1[ Hello주소 ] << 8바이트
	// pp[ &msg ] << 8바이트

	const char** pp = &msg;
	SetMessage(&msg);

	// [매개변수][RET][지역변수(msg( Hello주소 ))][매개변수(a( &msg msg의 주소 ))][RET][지역변수]

	SetMessage2(msg);
	cout << msg << endl;


	return 0;

}