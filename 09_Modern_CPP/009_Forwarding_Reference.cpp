#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// ���� ����(forwarding reference)

class Knight
{
public:
	Knight() { cout << "�⺻ ������" << endl; }
	Knight(const Knight&) { cout << "���� ������" << endl; }
	Knight(Knight&&) noexcept { cout << "�̵� ������" << endl; }

};

void Test_RValueRef(Knight&& k) // ������ ����
{

}

void Test_Copy(Knight k)
{

}

template<typename T>
void Test_ForwardingRef(T&& param) // ���� ����
{
	// �ް� ������� ����
	// ������ ������� �̵�
	Test_Copy(forward<T>(param));
}

int main()
{
	// ���� ����(universal reference)
	// ���� ����(forwarding reference) C++17

	// && : &�� �ι� -> ������ ����

	Knight k1;

	Test_RValueRef(move(k1)); // rvalue_cast

	//Test_ForwardingRef(k1);
	//Test_ForwardingRef(move(k1));

	auto&& k2 = k1;
	auto&& k3 = move(k1);

	// ������ : ���� ���� (type deduction)�� �Ͼ ��

	// ���� ������ �����ϴ� ���
	// ---------------------------------------

	Knight& k4 = k1; // �ް� ����
	Knight&& k5 = move(k1); // ������ ����

	// ������ : �ް��� �ƴϴ� = ���ϽĿ��� ���Ƴ��� ��� X
	// ������ ���� : �������� ���� �� �� �ִ� ���� Ÿ��
	// Test_RValueRef(move(k5)); // k5 ��ü�� ������ ������ �ƴϴ�

	Test_ForwardingRef(k1);
	Test_ForwardingRef(move(k1));


	return 0;
}