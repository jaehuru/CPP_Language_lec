#include <iostream>

using namespace std;

// const

// �ѹ� �������� ���� �ٲ��� ���� ����
// constant�� ������ const�� ���� (������ ���ȭ �Ѵٰ� ��)
// const�� �ٿ����� �ʱⰪ�� �ݵ�� �����ؾ� ��

// ���� ����

// [������ ����]
// .data
int a = 2;
// .bss (�ʱⰪ�� ���� ���)
int b;
// .rodata (�б� ���� ������)
const char* msg = "Hello World";


int main()
{
	// const�� �ٲ��� �ʴ� �б� ����?
	// �����Ϸ� �������
	const int AIR = 0;
	const int STUN = 1;
	const int POLYMORPH = 2;
	const int INVINCIBLE = 3;


	return 0;
}