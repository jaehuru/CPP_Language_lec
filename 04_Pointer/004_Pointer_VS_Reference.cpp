#include <iostream>

using namespace std;

struct StatInfo
{
	int hp;     // +0
	int attack; // +4
	int defence;// +8
};

// [�Ű�����][RET][��������(info)] [�Ű�����(&info)][RET][��������]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 5;
	info->defence = 1;
}

// [�Ű�����][RET][��������(info)] [�Ű�����(info)][RET][��������]
void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 5;
	info.defence = 1;
}

// ���� �������� �ʴ´ٸ�, ���� �� �ϴ� ���� ����

// 1) �� ���� ���
// [�Ű�����][RET][��������(info)] [�Ű�����(info)][RET][��������)]
void PrintInfoByCopy(StatInfo info)
{
	cout << "--------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "--------------------" << endl;
}

// 2) �ּ� ���� ���
// [�Ű�����][RET][��������(info)] [�Ű�����(&info)][RET][��������)]
void PrintInfoByPtr(StatInfo* info)
{
	cout << "--------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "--------------------" << endl;
}

// StatInfo ����ü�� ���� ����ü���?
// - (�� ����) ���� ���� ����Ǵ�
// - (�ּ�����) 8����Ʈ..!
// - (��������) 8����Ʈ..!

// �� ����ó�� ���ϰ� ����ϰ�
// �ּ� ����ó�� �ּҰ��� �̿��� �˸��̸� �ǵ帮��
// �ϼ������� ���

void PrintInfoByRef(StatInfo& info)
{
	cout << "--------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "--------------------" << endl;
}

int main()
{	
	StatInfo info;

	StatInfo* pointer;
	pointer = &info;

	StatInfo& reference = info;

	// ������ vs ���� ������ ���

	// ���� : �Ȱ���!

	// ���Ǽ� : ���� ��!

	// 1) ���Ǽ� ����
	// ���Ǽ��� ���ٴ°� �� �������� �ƴϴ�.
	// �����ʹ� �ּҸ� �ѱ�� Ȯ���ϰ� ������ �ѱ�ٴ� ��Ʈ�� ��.
	// ������ �ڿ������� �𸣰� ����ĥ ���� ����.

	// const�� ���
	// ����� �����͵� const�� ���
	// * �������� �տ� ���̴��� �ڿ� ���̴��� ���̰� ����
	// �� �ڿ� ���̸�
	// info��� �ٱ����� ���빰(�ּ�)�� �ٲ� �� ����
	// info��� �ּҰ��� ���� �ٱ��� -> �� �ּҰ��� �����̴�!

	// �� �տ� ���̸�
	// info�� '����Ű�� �ִ�' �ٱ����� ���빰�� �ٲ� �� ����
	// '����' �ٱ����� ���빰�� �ٲܼ� ����
	// info[ �ּҰ� ] �ּҰ�[ ������ ]
	// info = &globalinfo; // ���� ����
	// info->hp = 10000; // ���� ����

	// 2) �ʱ�ȭ ����
	// ���� Ÿ���� �ٱ����� 2��° �̸�
	// -> �����ϴ� ����� ������ �ȵ�
	// �ݸ� �����ʹ� �׳� �~ �ּҶ�� �ǹ�
	// -> ����� �������� ���� ���� ����
	// �����Ϳ��� '����'�� �ǹ̷� ? nullptr
	// ���� Ÿ���� �̷� nullptr�� ������ ����

	StatInfo* pointer = nullptr;

	//pointer = &info;

	PrintInfoByPtr(pointer);

	StatInfo& reference = info;

	PrintInfoByRef(reference);

	// �׷��� �����?
	// �������� ������ ���� ����
	// ���ۿ��� ������ ��ȣ
	// �𸮾� �������� ���� ��ȣ
	// Rookiss ��ȣ ��Ÿ��)
	// - ���� ��� ������
	// - �ٲ��� �ʰ� �д� �뵵 const ref&
	// �����ͷ� ����ϴ��� ������ �Ѱ��ַ���?
	// pointer [ �ּ�(&info) ] -> ref, info[ ������ ]
	// Statinfo& ref = *pointer;

	PrintInfoByRef(*pointer);


	// ������ ����ϴ��� �����ͷ� �Ѱ��ַ���?
	// pointer [ �ּ� ] -> reference, info[ ������ ]

	PrintInfoByPtr(&reference); 
}