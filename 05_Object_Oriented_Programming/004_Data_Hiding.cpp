#include <iostream>

using namespace std;

// ��ü���� (OOP: Object Oriented Programming)

// - ��Ӽ�
// - ���м�
// - ������
// ���м�(Data Hiding) = ĸ��ȭ(Encapsulation)
// ���� �Ǵ� ���� ����ϰ� ����ڴ�!

// ����?
// 1) �����ϰ� �ǵ帮�� �ȵǴ� ���
// 2) �ٸ� ��η� �����ϱ� ���ϴ� ���

// �ڵ���
// - �ڵ�
// - ���
// - ����
// - ��
// - ���� ���⼱

// �Ϲ� ������ ���忡�� ����ϴ� ��?
// - �ڵ�
// - ���
// - ��

// ���� �Ǵ� �κ� (�ǵ帮�� ū�ϳ�)
// - ����
// - ���� ���⼱

// public (������) protected (��ȣ�޴�) private (��������)
// public : �������׳� ����. ���� ����Ͻ�
// protected : ���� �ڼյ����״� ���
// private : ���� ����Ҳ� << class Car ���ο�����

// ��� ���� ������ : ���� �������� �θ���� ������ ��� ��������?
// �θ������ �������� ������ �� ���� �ڼյ����׵� �Ȱ��� ������� ���� ����
// - public : ������ ���? �θ���� ���� ���� �״��~ (public -> public, protected -> protected)
// - protected : ��ȣ�޴� ���? �� �ڼյ� ���׸� �����ٲ��� (public -> protected, protected -> protected)
// - private : �������� ��� �������� �� ���� �ڼյ����״� �ƿ� �� �����ٲ���~ �� private��~

class Car
{
public: // (���) ���� ������
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}
	void TurnKey()
	{
		RunEngine();
	}

protected:
	void RunEngine() {}

private:
	void ConnectCircuit() {}
	void DisassembleCar() {}

public:
	// �ڵ� / ��� / ���� / �� / ���� ���⼱
};

class SuperCar : public Car // ��� ���� ������
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
};

class TestSuperCar : SuperCar // public �ۼ����ϸ� private�� �ڵ�����
{
	void Test()
	{
		RunEngine();
	}
};

// 'ĸ��ȭ'
// ������ �����Ϳ� �Լ��� �������� ������� ��

class Berserker
{

public:
	int GetHp() { return _hp; }

	// ��� : ü���� 50 ���Ϸ� �������� ����Ŀ ��� �ߵ�(������)

	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}

private:
	void SetBerserkerMode()
	{
		cout << "�ſ� ������!" << endl;
	}

private:
	int _hp = 100;
};

int main()
{
	Berserker b;
	b.SetHp(20);
	return 0;
}

