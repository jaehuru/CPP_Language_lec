#include <iostream>

using namespace std;

// 반복문

int main()
{
	// while ~동안에
	// 한번만 실행하는게 아니라 특정 조건까지 계속 반복해야 하는 상황
	// ex) 게임을 끌 때까지 계속 게임을 실행시켜야할 때

	// 루프문의 흐름 제어
	// break; contine;
	
	int count = 0;

	while (count < 5)
	{
		cout << "Hello World" << endl;
		count++;
	}

	// 무조건 한번은 실행하는 차이 (거의 사용을 안함!)
	/*do 
	{
		cout << "Hello World" << endl;
		count++;
	} while (count < 5);*/

	for (int i = 0; i < 5; i++)
	{
		cout << "Hello World" << endl;
	}


	return 0;
}