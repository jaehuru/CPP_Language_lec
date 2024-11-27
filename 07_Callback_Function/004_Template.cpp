#include <iostream>

using namespace std;

// ���ø� ����

class Knight
{
public:
	// ...

public:
	int _hp = 100;
};


template<typename T> // ������ �������� �Լ�Ʋ�� ��
// template<class T> // SAME ��������
void Print(T a)
{
	cout << a << endl;
}

// ���ø� Ư��ȭ
template<>
void Print(Knight a)
{
	cout << "Knight !!!!!" << endl;
	cout << a._hp << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

// ������ �����ε� (�����Լ� ����)
ostream& operator<<(ostream& os, const Knight& k)
{
	os << k._hp;
	return os;
}

int main()
{
	// ���ø� : �Լ��� Ŭ������ ���� Ʋ
	// 1) �Լ� ���ø�
	// 2) Ŭ���� ���ø�

	Print<int>(50);
	Print(50.345f);
	Print(50.12334);
	Print("Hello World");

	Print("Hello", 100);

	int result1 = Add<int>(1, 5);
	float result2 = Add(0.2f, 0.5f);

	Knight k1;
	Print(k1);

	return 0;
}