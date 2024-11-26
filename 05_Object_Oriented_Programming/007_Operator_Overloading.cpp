#include <iostream>

using namespace std;

// ������ vs �Լ�

// - �����ڴ� �ǿ������� ����/Ÿ���� �����Ǿ� ����
// ������ �����ε�?
// �ϴ� [������ �Լ�]�� �����ؾ� ��
// �Լ��� ����Լ� vs �����Լ��� �����ϴ°�ó��, ������ �Լ��� �ΰ��� ������� ���� �� ����

// - ��� ������ �Լ� .ver
// -- a op b ���¿��� ���� �������� ���ܵ� (a�� Ŭ�������� ����. a�� '���� �ǿ�����'��� ��)
// -- �Ѱ�) a�� Ŭ������ �ƴϸ� ��� ����
// 
// - ���� ������ �Լ� version
// -- a op b ���¶�� a, b ��θ� ������ �Լ��� �ǿ����ڷ� ������ش�

// �׷� ������ �� ������? �׷��� ����. ������ �� �� �ϳ��� �����ϴ� ��쵵 �ֱ� ����.
// - ��ǥ������ ���� ������ (a = b)�� ���� ������ version���δ� �� �����

// ���� ���� ������
// - ���� ���� ������ = ���� ������ ��, �ڱ� �ڽ��� ���� Ÿ���� ���ڷ� �޴� ��

// ��Ÿ
// - ��� �����ڸ� �� �����ε� �� �� �ִ� ���� �ƴϴ� (:: . .* �̷��� �ȵ�)
// - ��� �����ڰ� �� 2�� ���� �ִ� �� �ƴ�. '++ --' �� ��ǥ�� (���� ������)
// - ���� ������ '++, --'
// -- ������ (++a) operator++()
// -- ������ (a++) operator++(int)

class Position
{
public:

	Position()
	{

	}

	// [���� ������]

	Position(const Position& arg)
	{

	}

	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = x + arg.x;
		pos._y = y + arg.y;

		return pos;
	}

	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;

		return pos;
	}

	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}

	Position& operator=(int arg)
	{
		_x = arg;
		_y = arg;

		// Position* this = ���ڽ��� �ּ�;

		return *this;
	}

	// [���� ������] [���� ���� ������] �� Ư�� ��츦 �޴� ������,
	// �� �״�� ��ü�� '����'�Ǳ� ���ϴ� Ư¡ ����
	// TODO : �����Ҵ��Ҷ� �ڼ��ϰ�

	Position& operator=(const Position& arg)
	{
		x = arg.x;
		y = arg.y;

		// Position* this = ���ڽ��� �ּ�;

		return *this;
	}

	Position& operator++()
	{
		_x++;
		_y++;

		return *this;
	}

	Position operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;
		return ret;
	}

public:
	int _x;
	int _y;

};

/*void operator=(const Position& a, int b)
{
a._x = b;
a._y = b;
}*/

Position operator+(int a, const Position& b)
{
	Position ret;
	ret._x = b._x + a;
	ret._y = b._y + a;

	return ret;
}

int main()
{
	Position pos1;
	pos1._x = 1;
	pos1._y = 1;

	Position pos2;
	pos2._x = 2;
	pos2._y = 2;
	Position pos3 = pos1 + pos2;

	//pos3 = pos3.operator+(pos2);

	Position pos4 = pos3 + 1;
	Position pos5 = 1 + pos3;
	bool isSame = (pos4 == pos5);

	Position pos6;
	pos3 = (pos6 = 5);

	// (const pos&) ��~~ (pos)���簪 �ٰ�

	pos5 = pos3++;
	++(++pos3);

	return 0;
}