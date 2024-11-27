#include <iostream>

using namespace std;

// ����

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
	cout << "DEF: " << info.defence<< endl;
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
	int number = 1;
	// �ο췹��(�����) ���������� ���� �۵� ����� �����Ϳ� ���� �Ȱ���..!
	int& ref = number;

	// C++ ���������� number��� �ٱ��Ͽ� �� �ٸ� �̸��� �ο��� ��.
	// number��� �ٱ��Ͽ� reference��� �ٸ� �̸��� �����ٰ�~
	// ������ reference �ٱ��Ͽ��ٰ� �� �����ų� ������
	// ���� number �ٱ��Ͽ��ٰ� �� ���� �����ų� ������ ��!
	ref = 3;

	// �׷��� ������ �ٸ� �̸��� ���� ������?
	// ���� ���� ����!

	StatInfo info;
	CreateMonster(&info);
	
	PrintInfoByCopy(info);
	PrintInfoByPtr(&info);
	PrintInfoByRef(info);

	return 0;
}