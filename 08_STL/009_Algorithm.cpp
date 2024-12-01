#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// �˰���

// �ڷᱸ�� (�����͸� �����ϴ� ����)
// �˰��� (�����͸� ��� ����� ���ΰ�?)

// find
// find_if
// count
// count_if
// all_of
// any_of
// none_of
// for_each

// remove
// remove_if


int main()
{
	vector<int> v;

	// Q1) number��� ���ڰ� ���Ϳ� üũ�ϴ� ���
	{
		int number = 50;
		vector<int>::iterator itFind = find(v.begin(), v.end(), number);

		if (itFind == v.end())
		{
			cout << "��ã����" << endl;
		}
		else
		{
			cout << "ã����" << endl;
		}
	}

	// Q2) 11�� ������ ���ڰ� ���Ϳ� �ִ��� üũ�ϴ� ���
	{
		struct CanDivideBy11
		{
			bool operator()(int n) { return n % 11 == 0; }
		};

		vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDivideBy11());

		if (itFind == v.end())
		{
			cout << "��ã����" << endl;
		}
		else
		{
			cout << "ã����" << endl;
		}

	}

	// Q3) Ȧ���� ������ ������?
	{
		int count = 0;

		struct IsOdd
		{
			bool operator()(int n) { return n % 2 != 0; }
		};

		count_if(v.begin(), v.end(), IsOdd());

		bool b1 = all_of(v.begin(), v.end(), IsOdd()); // ��� �����Ͱ� Ȧ�� �Դϱ�?
		bool b2 = any_of(v.begin(), v.end(), IsOdd()); // Ȧ���� �����Ͱ� �ϳ��� �ֽ��ϱ�?
		bool b3 = none_of(v.begin(), v.end(), IsOdd()); // ��� �����Ͱ� Ȧ���� �ƴմϱ�?
	}

	// Q4) ���Ϳ� �� �ִ� ��� ���ڵ鿡 3�� �����ּ���!
	{
		struct MultiplyBy3
		{
			void operator()(int& n) { n *= 3; }
		};

		for_each(v.begin(), v.end(), MultiplyBy3());
	}

	// Ȧ���� �����͸� �ϰ� ����
	{
		v.push_back(1);
		v.push_back(4);
		v.push_back(3);
		v.push_back(5);
		v.push_back(8);
		v.push_back(2);
		
		// 1 4 3 5 8 2
		// 4 4 3 5 8 2
		// 4 8 2       5 8 2

		
		// 4 8 2 5 8 2

		// remove(v.begin(), v.end(), 4);

		struct IsOdd
		{
			bool operator()(int n) { return n % 2 != 0; }
		};

		// remove_if(v.begin(), v.end(), IsOdd()); // 4 8 2 5 8 2
		v.erase(remove_if(v.begin(), v.end(), IsOdd()), v.end()); // 4 8 2
	}

	return 0;
}