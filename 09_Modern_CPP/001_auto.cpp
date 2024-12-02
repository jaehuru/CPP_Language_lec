#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// auto

class Knight
{
public:
	int _hp;
};

template<typename T>
void Print(T t)
{
	cout << t << endl;
}

int main()
{
	// Modern C++ (C++11)

	/*
	int a = 3;
	float b = 3.14f;
	double c = 1.23;
	Knight d = Knight();
	const char* e = "jaehuru";
	*/

	auto a = 3;
	auto b = 3.14f;
	auto c = 1.23;
	auto d = Knight();
	auto e = "jaehuru";

	// auto�� ������ ��Ŀī��
	// ���� ���� (type deduction)
	// -> ���� �ǰ� �� �����~ (�߷�)
	// �߷� ��Ģ�� �������� �������� �� �ִ�

	// ����!
	// �⺻ auto�� const, & ���� !!
	int& ref = a;
	const int cst = a;

	auto test1 = ref;
	auto test2 = cst;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (auto i = 0; i < v.size(); i++)
	{
		auto& data = v[i];

		data = 100;
	}

	// ���� ������ Ÿ���� �ؾ������ auto�� ����ҷ���~
	// NO!
	// -> Ÿ������ ������� ��� OK
	// -> �������� ���ؼ� �Ϲ������� ���δ°� ����
	// ex)
	map<int, int>m;
	auto ok = m.insert(make_pair(1, 100));

	for (auto it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}