#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 오른값 참조와 std::move (모던C++의 꽃)
class Pet
{
	
};

class Knight
{
public:
	Knight()
	{
		cout << "Knight()" << endl;
	}

	// 복사 생성자
	Knight(const Knight& knight)
	{
		cout << "const Knight()" << endl;
	}

	// 이동 생성자
	Knight(Knight&& knight)
	{

	}

	~Knight()
	{
		if (_pet)
			delete _pet;
	}

	// 복사 대입 연산자
	void operator=(const Knight& knight)
	{
		cout << "operator=(const Knight)" << endl;

		// 깊은 복사
		_hp = knight._hp;

		if (knight._pet)
			_pet = new Pet(*knight._pet);
	}

	// 이동 대입 연산자
	void operator=(Knight&& knight) noexcept
	{
		cout << "operator=(const Knight&&)" << endl;

		// 얕은 복사
		_hp = knight._hp;
		_pet = knight._pet;

		knight._pet = nullptr;
	}

public:
	int _hp = 100;
	Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight) { }
void TestKnight_LValueRef(Knight& knight) { }
void TestKnight_ConstLValueRef(const Knight& knight) { } // 원본 수정해서는 안돼 읽는건 가능
void TestKnight_RValueRef(Knight&& knight) { knight._hp = 20; } // 이동 대상!

int main()
{
	// 왼값(lvalue) vs 오른값(rvalue)
	// - lvalue : 단일식을 넘어서 계속 지속되는 개체
	// - rvalue : lvalue가 아닌 나머지 (임시 값, 열거형, 람다, i++ 등)

	int a = 3;
	
	Knight k1;
	
	TestKnight_Copy(k1);

	TestKnight_LValueRef(k1);
	//TestKnight_LValueRef(Knight());
	TestKnight_ConstLValueRef(Knight());

	TestKnight_RValueRef(Knight());

	TestKnight_RValueRef(static_cast<Knight&&>(k1));

	Knight k2;
	k2._pet = new Pet();
	k2._hp = 1000;

	// 원본은 날려도 된다 << 는 Hint를 주는 쪽에 가깝다!
	Knight k3;

	//k3 = static_cast<Knight&&>(k2);
	k3 = move(k2); // 오른값 참조로 캐스팅
	// move의 본래 이름 후보중 하나가 rvalue_cast

	unique_ptr<Knight> uptr = make_unique<Knight>();
	unique_ptr<Knight> uptr2 = move(uptr);

	return 0;
}