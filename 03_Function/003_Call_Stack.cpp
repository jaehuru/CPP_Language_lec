#include <iostream>

using namespace std;

// ȣ�� ����

// ���尡 ���� �ʴ´�... 
// �� ������? �������� �� ���������� �м��� �ϱ� ������ Func1 �Լ����� Func2�� ��;

// ���� �Լ��� �������ָ� �ذ�! (�ּ��� Ǯ�� �ذ��)
//void Func1();
//void Func2(int a, int b);
//void Func3(float a);

// �Լ��� ȣ��Ǵ� ������ �����ִ°��� ȣ�� ����
// ����� ȣ�⽺���� ������Ҷ� �����ϴ�!

void Func1()
{
	cout << "Func1" << endl;

	Func2(1, 2);
}

void Func2(int a, int b)
{
	cout << "Func2" << endl;

	Func3(10.f);
}

void Func3(float a)
{
	cout << "Func3" << endl;
}

int main()
{
	cout << "Main" << endl;
	Func1();
	

	return 0;
}