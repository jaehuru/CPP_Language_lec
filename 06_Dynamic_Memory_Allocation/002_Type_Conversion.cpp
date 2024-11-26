#include <iostream>

using namespace std;

// malloc -> void* �� ��ȯ�ϰ�, �̸� �츮�� (Ÿ�� ��ȯ)�� ���� ����߾���

class Knight
{

public:
	int _hp = 10;

};

class Dog
{
public:

	Dog()
	{

	}

	// Ÿ�� ��ȯ ������
	Dog(const Knight& knight)
	{
		age = knight.hp;
	}

	// Ÿ�� ��ȯ ������
	operator Knight()
	{
		return (Knight)(*this);
	}

public:
	int _age = 1;
	int _cuteness = 2;

};

class BullDog : public Dog
{

public:

public:
	bool _french;

};

int main()
{
	// --------- Ÿ�� ��ȯ ���� (��Ʈ�� �籸�� ����) -----------
	// [1] �� Ÿ�� ��ȯ
	// Ư¡) �ǹ̸� �����ϱ� ���ؼ�, ���� ��ü�� �ٸ� ��Ʈ�� �籸��

	{
		int a = 123456789; // 2�� ����
		float b = (float)a; // �ε��Ҽ���(���� + ��ȿ����)
		cout << b << endl;
	}

	// [2] ���� Ÿ�� ��ȯ
	// Ư¡) ��Ʈ���� �籸������ �ʰ�, '����'�� �ٲ�� ��
	// ���� ������ ������, ������ Ÿ�� ��ȯ�� '���� Ÿ�� ��ȯ' ������ ���� �����ϱ� �ϼ������� ��������!

	{
		int a = 123456789; // 2�� ����
		float b = (float&)a; // �ε��Ҽ���(���� + ��ȿ����)
		cout << b << endl;
	}

	// --------- ������ �з� -----------
	// [1] ������ ��ȯ
	// Ư¡) �ǹ̰� �׻� 100% ������ ��ġ�ϴ� ���
	// ���� �ٱ��Ͽ��� ū�ٱ��Ϸ� �̵� ok (��ĳ����)
	// ex_ char -> short, short -> int, int -> __int64

	{
		int a = 123456789;
		__int64 b = a;
		cout << b << endl;
	}

	// [2] �Ҿ����� ��ȯ
	// Ư¡) �ǹ̰� �׻� 100& ��ġ�Ѵٰ� �������� ���ϴ� ���
	// Ÿ���� �ٸ��ų�
	// ���� Ÿ�������� ū �ٱ��� -> ���� �ٱ��� �̵� (�ٿ�ĳ����)

	{
		int a = 123456789;
		float b = a;
		short c = a;

		cout << b << endl;

		cout << c << endl;
	}

	// --------- ���α׷��� �ǵ��� ���� �з� -----------

	// [1] �Ͻ��� ��ȯ
	// Ư¡) �̹� �˷��� Ÿ�� ��ȯ ��Ģ�� ���� �����Ϸ� '�ڵ�'���� Ÿ�� ��ȯ

	{
		int a = 123456789;
		float b = a; // �Ͻ���
		cout << b << endl;
	}

	// [2] ������ ��ȯ

	{
		int a = 123456789;
		int* b = (int*)a; // ������
		cout << b << endl;
	}

	// --------- �ƹ��� ���� ���谡 ���� Ŭ���� ������ ��ȯ -----------
	// [1] �������� Ŭ���� ������ '�� Ÿ��' ��ȯ
	// Ư¡) �Ϲ������� �� �� (���� : Ÿ�� ��ȯ ������, Ÿ�� ��ȯ ������)

	{
		Knight knight;
		Dog dog = (Dog)knight;
		Knight knight2 = dog;
	}

	// [2] �������� Ŭ���� ������ ���� Ÿ�� ��ȯ
	// Ư¡) ���������� ok

	{
		Knight knight;

		// ������� : ������ = ����

		Dog& dog = (Dog&)knight;
		dog._cuteness = 12;
	}

	// --------- ��� ���迡 �ִ� Ŭ���� ������ ��ȯ -----------
	// Ư¡) �ڽ� -> �θ� ok, �θ� -> �ڽ� no
	// [1] ��� ���� Ŭ������ �� Ÿ�� ��ȯ

	{
		//Dog dog;
		//BullDog bulldog = dog;
		BullDog bulldog;
		Dog dog = bulldog;
	}

	// [2] ��� ���� Ŭ������ ���� Ÿ�� ��ȯ
	// Ư¡) �ڽ� -> �θ� ok, �θ� -> �ڽ� (������)ok

	{
		/*Dog dog;
		BullDog& bulldog = (BullDog&)dog;*/
		BullDog bulldog;
		Dog& dog = bulldog;
	}

	// ���)
	// [�� Ÿ�� ��ȯ] : ��¥ ��Ʈ���� �ٲٰ�~ ���������� ���� �ǰ� �ٲٴ� ��ȯ
	// - ���������� ���� �ȴ�? (ex. BullDog -> Dog) Ok
	// - ���������� ���� �� �ȴ� (ex. Dog -> BullDog, Dog -> Knight) �� ��

	// [���� Ÿ�� ��ȯ] : ��Ʈ���� ���ΰ� �츮�� '����'�� �ٲٴ� ��ȯ
	// - ���� �θ���(������ �䱸) ���ֱ� �ϴµ�, �� ���ص� '�׳�' (�Ͻ���)���� ���ִ����� ������ ���θ� ���� ����
	// -- �����ϴ�? �׳� �Ͻ������� ok
	// -- �����ϴ�
	// --- �޸� ħ�� ������ �ִ� ��� '�׳�' ������ ����
	// --- ���������� ���� �ϰڴٰ� ���� ������ �ϸ� ok

	return 0;
}