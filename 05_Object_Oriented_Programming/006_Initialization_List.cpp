#include <iostream>

using namespace std;

// 초기화는 왜할까?
// - 버그 예방에 중요
// - 포인터 등 주소값이 연루되어 있을 경우

// 초기화 방법
// - 생성자 내에서
// - 초기화 리스트 : 선처리영역에서
// - C++11 문법 : 바로 초기화해버리기

// 초기화 리스트
// - 상속 관계에서 원하는 부모 생성자 호출할 떄 필요
// - 생성자 내에서 초기화 vs 초기화 리스트
// -- 일반 변수는 별 차이 없음
// -- 멤버 타입이 클래스인 경우 차이가 난다
// -- 정의함과 동시에 초기화가 필요한 경우 (참조타입, const 타입)

class Inventory
{
public:
	Inventory()
	{
		cout << "Inventory()" << endl;
	}

	Inventory(int size)
	{
		cout << "Inventory(int size)" << endl;
	}

	~Inventory()
	{
		cout << "~Inventory()" << endl;
	}

public:

};

class Player
{

};

// Is-A (Knight Is-A Player?) OK 상속

// Has-A (Knight Has-A Inventory?) OK 포함

class Knight : public Player
{

public:
	Knight() :
	_hp(100),
	_inventory(20),
	_hpRef(_hp),
	_hpConst(_hp)
	{

	}

public:
	int _hp; // 쓰레기 값
	Inventory _inventory;
	int& _hpRef;
	const int _hpConst;
};

int main()
{
	Knight k;
	cout << k._hp << endl;

	return 0;
}

