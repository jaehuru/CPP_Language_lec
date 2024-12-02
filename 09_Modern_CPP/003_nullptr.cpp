#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// nullptr

class Knight
{
public:
	void Test()
	{

	}
};

Knight* FindKnight()
{
	//TODO
	return nullptr;
}

void Test(int a)
{
	cout << "테스트" << endl;
}

void Test(int* ptr)
{
	cout << "테스트(*)" << endl;
}

// NullPtr 구현

const
class
{
public:
	// 그 어떤 타입의 포인터와도 치환 가능
	template<typename T>
	operator T* ()const { return 0; }

	// 그 어떤 타입의 멤버 포인터와도 치환 가능
	template<typename C, typename T>
	operator T C::* () const { return 0; }

private:
	void operator&() const; // 주소값 &을 막는다

} _nullptr;

int main()
{
	// 0 NULL
	int* ptr = NULL;

	// 1) 오동작
	Test(0);
	Test(NULL);
	Test(_nullptr); // GOOD

	// 2) 가독성
	Knight* knight = FindKnight();
	if (knight == _nullptr)
	{

	}

	void (Knight:: * memFunc)();
	memFunc = &Knight::Test;

	if (memFunc == _nullptr)
	{

	}

	//nullptr_t whoami = nullptr;


	return 0;
}