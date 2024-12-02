#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// ������ ������ std::move (���C++�� ��)
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

	// ���� ������
	Knight(const Knight& knight)
	{
		cout << "const Knight()" << endl;
	}

	// �̵� ������
	Knight(Knight&& knight)
	{

	}

	~Knight()
	{
		if (_pet)
			delete _pet;
	}

	// ���� ���� ������
	void operator=(const Knight& knight)
	{
		cout << "operator=(const Knight)" << endl;

		// ���� ����
		_hp = knight._hp;

		if (knight._pet)
			_pet = new Pet(*knight._pet);
	}

	// �̵� ���� ������
	void operator=(Knight&& knight) noexcept
	{
		cout << "operator=(const Knight&&)" << endl;

		// ���� ����
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
void TestKnight_ConstLValueRef(const Knight& knight) { } // ���� �����ؼ��� �ȵ� �д°� ����
void TestKnight_RValueRef(Knight&& knight) { knight._hp = 20; } // �̵� ���!

int main()
{
	// �ް�(lvalue) vs ������(rvalue)
	// - lvalue : ���Ͻ��� �Ѿ ��� ���ӵǴ� ��ü
	// - rvalue : lvalue�� �ƴ� ������ (�ӽ� ��, ������, ����, i++ ��)

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

	// ������ ������ �ȴ� << �� Hint�� �ִ� �ʿ� ������!
	Knight k3;

	//k3 = static_cast<Knight&&>(k2);
	k3 = move(k2); // ������ ������ ĳ����
	// move�� ���� �̸� �ĺ��� �ϳ��� rvalue_cast

	unique_ptr<Knight> uptr = make_unique<Knight>();
	unique_ptr<Knight> uptr2 = move(uptr);

	return 0;
}