#include <iostream>

using namespace std;

// �޸� ����

int& TestRef()
{
	int a = 1;
	return a;
}

int* TestPointer()
{
	int a = 1;
	return &a;
}

void TestWrong(int* ptr)
{
	int a[100] = { };
	a[99] = 0xAAAAAAAA;
	*ptr = 0x12341234;
}

int main()
{
	// �ּҸ� ��� �ٱ���
	// ������ ��~ �ָ� ��򰡿� ����
	// p�� ���� �� ������ �����ϴ� ��Ż

	int* p;

	// ��¥���! ���� ������
	// ����ó�� �������� ���� (��û ���� �Ŵ���)

	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// [�迭�� �̸�]�� �迭�� ���� �ּҰ��� ����Ű�� TYPE*�� �����ͷ� ��ȯ ����!

	p = arr;

	// [TYPE�� 1���� �迭]�� [TYPE*�� ������]�� ������ ȣȯ�� �ȴ�

	cout << p[0] << endl;
	cout << arr[0] << endl;
	cout << p[5] << endl;
	cout << arr[5] << endl;
	cout << *p << endl; // p[0]
	cout << *arr << endl; // arr[0]
	cout << *(p + 3) << endl;
	cout << *(arr + 3) << endl;

	// ������ �����帮�ڽ��ϴ�. (2���� �迭 vs ���� ������)

	int arr2[2][2] = { {1, 2}, {3, 4} };

	// pp[ �ּ�1 ]
	// �ּ�1 [ �ּ�2 ]
	// �ּ�2[ ]


	// 00000001[ ] << �޸𸮰��� �ּҰ����� ���� ������ ����ó���� ��
	// �ּ�1 [ 00000001 ] �ּҰ��� �޸𸮰�
	// pp[ �ּ�1 ]

	// int** pp = (int**)arr2;

	// cout << (**pp) << endl;

	// [ �ּ� ]
	// [ 1 ][ 2 ]

	int(*p2)[2] = arr2;

	cout << (*p2)[0] << endl;
	cout << (*p2)[1] << endl;
	cout << (*(p2 + 1))[0] << endl;
	cout << (*(p2 + 1))[1] << endl;
	cout << p2[0][0] << endl;
	cout << p2[0][1] << endl;
	cout << p2[1][0] << endl;
	cout << p2[1][1] << endl;

	// [�Ű�����][RET][��������] [�Ű�����][RET][��������(a)]

	int* pointer = TestPointer();
	TestWrong(pointer);

	return 0;
}