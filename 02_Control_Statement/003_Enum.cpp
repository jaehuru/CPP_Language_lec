#include <iostream>

using namespace std;

// ������

// ���ڸ� ���� ���ϸ� ù ���� 0���� ����
// �� ���� ������ ���� �� +1
enum ENUM_SRP
{
	ENUM_SCISSORS,
	ENUM_ROCK,
	ENUM_PAPER,
};

// #�� ������ -> ��ó�� ���ù�
// #include <iostream> �̶�� ������ ã�Ƽ� �ش� ������ ��ü ����!
// 1) ��ó�� 2) ������ 3) ��ũ
#define DEFINE_SCISSORS 1
#define DEFINE_ROCK 2
#define DEFINE_PAPER 3
#define DEFINE_TEST cout << "Hello World" << endl;

int main()
{
	DEFINE_TEST;

	return 0;
}