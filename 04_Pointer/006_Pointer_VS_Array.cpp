#include <iostream>

using namespace std;

void Test(int a)
{
	a++;
}

// �迭�� �Լ� ���ڷ� �ѱ��, �����Ϸ��� �˾Ƽ� �����ͷ� ġȯ�Ѵ� (char[] -> char*)
// �� �迭�� ���� ��ü�� �ѱ�� �ƴ϶�, ���� �ּ�(������)�� �ѱ� ��

void Test(char a[])
{
	a[0] = 'x';
}

int main()
{
	// .data �ּ� [H][e][l][l][o][][W][o][r][l][d][\0]
	// test1[ �ּ� ] << 8����Ʈ

	const char* test1 = "Hello World";

	//test1[0] = 'R'; �Ұ���
	// .data �ּ� [H][e][l][l][o][][W][o][r][l][d][\0]
	// [H][e][l][l][o][][W][o][r][l][d][\0] 4����Ʈ�� ���
	// test2 = �ּ�

	char test2[] = "Hello World";

	//test2[0] = 'R';
	//cout << test2 << endl;
	// �����ʹ� [ �ּҸ� ��� �ٱ��� ]
	// �迭�� [����] ��, �� ��ü�� ���� �����ͳ��� �پ��ִ� '�ٱ��ϸ���'
	// -�ٸ� [�迭�̸�]�� '�ٱ��� ����'�� [ ���� �ּ� ]
	// �迭�� �Լ��� ���ڷ� �ѱ�� �Ǹ�?

	int a = 0;

	// [�Ű�����][RET][��������(a=0)][�Ű�����(a=1)][RET][��������]

	Test(a);
	cout << a << endl;

	// �ٲ��!

	Test(test2);
	cout << test2 << endl;

	return 0;

}