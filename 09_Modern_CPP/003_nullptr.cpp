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
	cout << "�׽�Ʈ" << endl;
}

void Test(int* ptr)
{
	cout << "�׽�Ʈ(*)" << endl;
}

// NullPtr ����

const
class
{
public:
	// �� � Ÿ���� �����Ϳ͵� ġȯ ����
	template<typename T>
	operator T* ()const { return 0; }

	// �� � Ÿ���� ��� �����Ϳ͵� ġȯ ����
	template<typename C, typename T>
	operator T C::* () const { return 0; }

private:
	void operator&() const; // �ּҰ� &�� ���´�

} _nullptr;

int main()
{
	// 0 NULL
	int* ptr = NULL;

	// 1) ������
	Test(0);
	Test(NULL);
	Test(_nullptr); // GOOD

	// 2) ������
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