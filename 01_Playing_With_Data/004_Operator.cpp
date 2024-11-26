#include <iostream>

using namespace std;

// ������ ������

int a = 1;
int b = 2;

int hp;

bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

bool test;
bool isInvincible = true;

int main()
{
#pragma region ��� ����

	// ��� ������
	// ���� ����

	// a �� b �� �����ϰ� b�� ��ȯ�϶�
	// -> b��� �ٱ��� �ȿ� �ִ� ����, a��� �ٱ��� �ȿ��� ����
	a = b;


	// ��Ģ ����
	a = b + 3; // ���� add
	a = b - 3; // ���� sub
	a = b * 3; // ���� mul
	a = b / 3; // ������ div
	a = b % 3; // ������ div

	a += 3; // a = a + 3;
	a -= 3;
	a *= 3;
	a /= 3;
	a %= 3;

	// ���� ������
	a++; // a = a + 1;
	++a;
	a--;
	--a;

	b = a++; // b = a -> a �� 1 ����
	b = ++a; // a�� 1���� -> b = a

#pragma endregion

#pragma region �� ����

	// a == b : a �� b�� ���� ������?
	// ������ 1, �ٸ��� 0
	isSame = (a == b);

	// a != b : a �� b�� ���� �ٸ���?
	// �ٸ��� 1, ������ 0
	isDifferent = (a != b);

	// a > b : a�� b���� ���� ū��?
	// a >= b : a�� b���� ���� ũ�ų� ������?
	// ũ�� 1, �ƴϸ� 0
	isGreater = (a > b);

	// a < b : a�� b���� ���� ������?
	// a <= b : a�� b���� ���� �۰ų� ������?
	// ������ 1, ������ 0
	isSmaller = (a < b);

#pragma endregion

#pragma region �� ����

	// ! not
	// 0�̸� 1, �׿� 0
	test = !isSame; // ��ǻ� isDifferent�� �ǹ�

	// && and
	// a && b -> �Ѵ� 1�̸� 1, �� �� 0
	test = (hp <= 0 && isInvincible == false); // ����

	// || or
	test = (hp > 0 || isInvincible == true); // ������

#pragma endregion

#pragma region ��Ʈ ����

	// ���� �ʿ��Ѱ�?
	// ��Ʈ ������ ������ �ʿ��Ҷ�
	// - ��ǥ������ bitFlag

	// ~ bitwise not
	// ���� ������ ��� ��Ʈ�� ������� 0�� 1, 1�� 0���� �ڹٲ�

	// & bitwise and
	// �� ������ ��� ��Ʈ ���� ������� and�� �Ѵ�

	// | bitwise or
	// �� ������ ��� ��Ʈ ���� ������� or�� �Ѵ�

	// ^ bitwise xor
	// �� ������ ��� ��Ʈ ���� ������� xor�� �Ѵ�

	// << ��Ʈ ���� �̵�
	// ��Ʈ���� N��ŭ �������� �̵�
	// ������ ��ġ�� N���� ��Ʈ�� ����. ���� �����Ǵ� N���� ��Ʈ�� 0.
	// *2�� �� �� ���� ���̴� ����

	// << ��Ʈ ���� �̵�
	// ��Ʈ���� N��ŭ ���������� �̵�
	// �������� ��ġ�� N���� ��Ʈ�� ����.
	// ���� �����Ǵ� N���� ��Ʈ��
	// - ��ȣ ��Ʈ�� ���� �� ��� ��ȣ ��Ʈ�� ���� (��ȣ�ִ� ������� �� �κ��� ����)
	// - �ƴϸ� 0

#pragma endregion

	return 0;
}