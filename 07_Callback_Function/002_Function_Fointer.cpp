#include <iostream>

using namespace std;

// �Լ� ������2

class Knight
{
public:

	// ��� �Լ�
	int GetHp(int, int)
	{
		cout << "Gethp()" << endl;
		return _hp;
	}

public:
	int _hp = 100;

};

// typedef �� ����
// typedef ���� -> ������ (Ŀ���� Ÿ�� ����)
typedef int NUMBER;

// ��Ȯ���� ����/������ ������ �ƴ϶�, [���� ����]���� typedef�� �տ��� ���̴� ��

typedef int INTEGER;
typedef int* POINTER;
typedef int (FUNC)(int, int);
typedef int ARRAY[20];

typedef int (*PFUNC)(int, int); // �Լ� ������

typedef int (Knight::*PMEMFUNC)(int, int); // ��� �Լ� ������

int Test(int, int)
{
	cout << "Test" << endl;
	return 0;
}

int t(int, int)
{
	cout << "t" << endl;
	return 0;
}

int main()
{
	// �Լ� ������
	// 1) ������            *
	// 2) ������ �̸�        fn
	// 3) Ÿ��              �Լ�(���ڷ� int 2���� �ް�, int 1���� ��ȯ)
	//int (*fn)(int, int);

	//typedef int(FUNC_TYPE)(int, int);
	//FUNC_TYPE* fn;

	PFUNC fn;

	fn = &Test; // & ���� ���� ( C��� ȣȯ�� ���� )

	fn(1, 2);
	(*fn)(1, 2);

	// �� �������� [���� �Լ� / ���� �Լ�]�� ���� �� �ִ� (ȣ�� �Ծ��� ������ �ֵ�)
	// fn = &Knight::GetHp; �Ұ���

	Test(1, 2);

	Knight k1;
	k1.GetHp(1, 1);

	PMEMFUNC mfn;
	mfn = &Knight::GetHp; // ��� �Լ����� &�ٿ��� ��
	(k1.*mfn)(1, 1);

	Knight* k2 = new Knight();
	(k2->*mfn)(1, 1);
	delete k2;

	return 0;
}