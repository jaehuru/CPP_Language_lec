#include <iostream>

using namespace std;

// ���� ������ �� ����

// ���� ����
// ����) �ʱ�ȭ ����, const �� .rodata .data .bss
int globalValue = 0;


void IncreaseHp(int hp) // main �������� ��ü�� ������ �ƴ϶� �ٸ� hp �̴�
{
	hp = hp + 1; // �ᱹ main ���������� �����ذ� �ƴ϶� �� �Լ���ü �Ű������� ���ϱ⸸ �Ѱ�
	// �� �Լ��� ���������� �ᱹ hp = 2 �� �ǰ� �ƹ��� ���� ����. !�ſ� �߿�
}

// [�Ű�����][RET][�������� (hp = 1)] [�Ű����� (�ٸ� hp = 1)][RET][�������� (hp = 2)]
int main()
{
	// ���� ����
	int localValue = 0;
	int hp = 1;

	IncreaseHp(hp);

	cout << "hp����? " << hp << endl; // ��? �� �ȹٲ���?

	return 0;
}