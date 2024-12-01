#include <iostream>
#include <vector>

using namespace std;

// ����



int main()
{
	// STL (Standard Template Library)
	// ���α׷����� �� �ʿ��� �ڷᱸ��/�˰������
	// ���ø����� �����ϴ� ���̺귯��

	// �����̳�(Container) : �����͸� �����ϴ� ��ü (�ڷᱸ�� Data Structure)

	// vector (���� �迭)
	// - vector�� ���� ���� (size/capacity)
	// - �߰� ����/����
	// - ó��/�� ����/����
	// - ���� ����

	// �迭
	const int MAX_SIZE = 10; 
	int arr[MAX_SIZE] = {};


	// ���� �迭
	// �ſ� �ſ� �߿��� ���� -> � ������ �ηȱ淡 �迭�� '����������' ����� ���ΰ�? !�߿�

	// 1) (�������� �ΰ�) �޸𸮸� �Ҵ��Ѵ�
	// 2) �����б��� �� á����, �޸𸮸� �����Ѵ�

	// Q1) �������� ��ŭ�� �����ұ�?
	// Q2) ������ ��ŭ �ؾ� �ұ�?
	// Q3) ������ �����͸� ��� ó���ұ�?

	vector<int> v(1000, 0);
	vector<int> v2 = v;

	//
	// v.resize(1000);
	cout << v.size() << " " << v.capacity() << endl;
	// size (���� ��� ������ ����)
	// 1 2 3 4 5 6 7 8 9 ...
	
	// v.reserve(1000); 
	// capacity (�������� ������ �뷮 ����)
	// 1 2 3 4 5 6 9 13 19 28 42 63 

	for (int i = 0; i < 1001; i++)
	{
		// v[i] = 100;
		v.push_back(100);
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.front();
	v.back();
	v.pop_back();

	v.clear();
	vector<int>().swap(v);
	cout << v.size() << " " << v.capacity() << endl;
	
	

	return 0;
}