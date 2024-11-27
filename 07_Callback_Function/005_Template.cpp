#include <iostream>

using namespace std;

// ���ø� ����

// typename T�� ���̸� '��Ŀī��' (� Ÿ�Ե� �� ���� �� ����)
// �׷��� ������ typename�� �ٿ��� �ϴ� ���� �ƴϴ�
// template< > �ȿ� ���°� [�������ϴ� ���]
template<typename T, int SIZE>
class RandomBox
{

public:
	T GetRandomData()
	{
		int idx = rand() % SIZE;
		return _data[idx];
	}

public:
	T _data[SIZE];

};

// ���ø� Ư��ȭ
template<int SIZE>
class RandomBox<double, SIZE>
{

public:
	double GetRandomData()
	{
		cout << "RandomBox double" << endl;
		int idx = rand() % SIZE;
		return _data[idx];
	}

public:
	double _data[SIZE];

};

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	// ���ø� : �Լ��� Ŭ������ ���� Ʋ
	// 1) �Լ� ���ø�
	// 2) Ŭ���� ���ø�
	RandomBox<int, 10> rb1;
	for (int i = 0; i < 10; i++)
	{
		rb1._data[i] = i;
	}
	int value1 = rb1.GetRandomData();
	cout << value1 << endl;
	
	/*RandomBox<float> rb2;
	for (int i = 0; i < 10; i++)
	{
		rb2._data[i] = i + 0.5f;
	}
	float value2 = rb2.GetRandomData();
	cout << value2 << endl;*/

	RandomBox<int, 20> rb3;
	for (int i = 0; i < 20; i++)
	{
		rb3._data[i] = i;
	}
	int value3 = rb3.GetRandomData();
	cout << value3 << endl;

	RandomBox<double, 20> rb4;
	for (int i = 0; i < 20; i++)
	{
		rb4._data[i] = i + 0.5;
	}
	double value4 = rb4.GetRandomData();
	cout << value4 << endl;

	
	return 0;
}