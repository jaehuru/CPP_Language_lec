#include <iostream>

using namespace std;

// �ݺ���

int main()
{
	// while ~���ȿ�
	// �ѹ��� �����ϴ°� �ƴ϶� Ư�� ���Ǳ��� ��� �ݺ��ؾ� �ϴ� ��Ȳ
	// ex) ������ �� ������ ��� ������ ������Ѿ��� ��

	// �������� �帧 ����
	// break; contine;
	
	int count = 0;

	while (count < 5)
	{
		cout << "Hello World" << endl;
		count++;
	}

	// ������ �ѹ��� �����ϴ� ���� (���� ����� ����!)
	/*do 
	{
		cout << "Hello World" << endl;
		count++;
	} while (count < 5);*/

	for (int i = 0; i < 5; i++)
	{
		cout << "Hello World" << endl;
	}


	return 0;
}