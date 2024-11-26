#include <iostream>

using namespace std;

// 참조

struct StatInfo
{
	int hp;     // +0
	int attack; // +4
	int defence;// +8
};

// [매개변수][RET][지역변수(info)] [매개변수(&info)][RET][지역변수]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 5;
	info->defence = 1;
}

// [매개변수][RET][지역변수(info)] [매개변수(info)][RET][지역변수]
void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 5;
	info.defence = 1;
}

// 값을 수정하지 않는다면, 양쪽 다 일단 문제 없음

// 1) 값 전달 방식
// [매개변수][RET][지역변수(info)] [매개변수(info)][RET][지역변수)]
void PrintInfoByCopy(StatInfo info)
{
	cout << "--------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence<< endl;
	cout << "--------------------" << endl;
}

// 2) 주소 전달 방식
// [매개변수][RET][지역변수(info)] [매개변수(&info)][RET][지역변수)]
void PrintInfoByPtr(StatInfo* info)
{
	cout << "--------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "--------------------" << endl;
}

// StatInfo 구조체가 대형 구조체라면?
// - (값 전달) 대형 값이 복사되는
// - (주소전달) 8바이트..!
// - (참조전달) 8바이트..!

// 값 전달처럼 편리하게 사용하고
// 주소 전달처럼 주소값을 이용해 알멩이를 건드리는
// 일석이조의 방식

void PrintInfoByRef(StatInfo& info)
{
	cout << "--------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "--------------------" << endl;
}


int main()
{
	int number = 1;
	// 로우레벨(어셈블리) 관점에서는 실제 작동 방식은 포인터와 완전 똑같음..!
	int& ref = number;

	// C++ 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것.
	// number라는 바구니에 reference라는 다른 이름을 지어줄게~
	// 앞으로 reference 바구니에다가 뭘 꺼내거나 넣으면
	// 실제 number 바구니에다가 그 값을 꺼내거나 넣으면 됨!
	ref = 3;

	// 그런데 귀찮게 다른 이름을 짓는 이유는?
	// 참조 전달 때문!

	StatInfo info;
	CreateMonster(&info);
	
	PrintInfoByCopy(info);
	PrintInfoByPtr(&info);
	PrintInfoByRef(info);

	return 0;
}