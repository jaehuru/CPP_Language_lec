#include <iostream>

using namespace std;

// �Լ� (���ν���, �޼ҵ�, ��ƾ)

/*
input���� ������ �ް�, output���� ������ ������ �����ش�

��ȯŸ�� �Լ��̸�([����Ÿ�� �Ű�����])
{
	�Լ� ����

	return ~~~;
}
*/

// Hello World�� �ֿܼ� ����ϴ� �Լ��� ������!
// input : ���� / output : ����
// Ÿ�� : int float double char ~~~ void

void PrintHelloWorld()
{
	cout << "Hello World" << endl;
}

// ������ �Է�(�Լ�) �޾Ƽ�, �ֿܼ� ����ϴ� �Լ��� ������
// input : int / output : ����
void PrintNumber(int number)
{
	cout << "�Ѱ��ֽ� ���ڴ� " << number << " �Դϴ�" << endl;
}

int MultiplyBy2(int a)
{
	return a * 2;
}

int MultiplyBy(int a, int b)
{
	return a * b;
}

int main()
{
	int num = MultiplyBy(3, 5);

	PrintNumber(num);

	return 0;
}