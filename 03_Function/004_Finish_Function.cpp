#include <iostream>

using namespace std;

// �Լ� ������

// �����ε� (�ߺ� ���� : �Լ� �̸��� ����)
// - �Ű����� ������ �ٸ��ų�
// - �Ű����� Ÿ���� �ٸ��ų� (������ �ٸ��� ����)
int Add(int a, int b)
{
	int sum = a + b;
	return sum;
}

int Add(int a)
{
	int sum = a + 1;
	return sum;
}

float Add(float a, float b)
{
	float sum = a + b;
	return sum;
}

// �⺻ ���ڰ�
void SetPlayerInfo(int hp, int mp, int attack, int guild_ID = 0) // �� �� �������� �⺻�� ������ ����
{

}

// ���� �����÷ο�
int Factorial(int n)
{
	if (n <= 1)
		return 1;
	return n * Factorial(n - 1);
}

int main()
{
	// int result = Add(1.5f, 2.1f); // ������ �ս��� �� �� �ִٰ� ��� ��.
	float result = Add(1.5f, 2.1f); // ������ �ս��� �� �� �ִٰ� ��� ��.

	cout << result << endl;

	SetPlayerInfo(100, 40, 10); // �⺻ ���� ������������

	int n = Factorial(1000000); // ���� �����÷ο�

	cout << n << endl;

	return 0;
}