#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

// deque

// vector : ���� �迭
// list : ���� ���� ����Ʈ
 
// «�͵� ���°� deque
 
// deque : double-ended queue ��ũ
// [   ]
// [   ]
// [   ]


int main()
{
	// ������ �����̳� (Sequence Container)
	// �����Ͱ� ���� ������� �����Ǵ� ����
	// vector / list / deque

	// vector�� ���������� �迭 ������� ����
	// �ٸ� �޸� �Ҵ� ��å�� �ٸ���

	// vector
	// [1  1  1] 
	// [1  1  1] 2  2] �ø��� ������ ����

	// deque
	// [      3  3] 1�� ��ȣ ����
	// [1  1  1  2] 2�� ��ȣ
	// [2         ] 3�� ��ȣ

	vector<int> v(3, 1);
	deque<int> d(3, 1);

	v.push_back(2);
	v.push_back(2);

	d.push_back(2);
	d.push_back(2);

	d.push_front(3);
	d.push_front(3);

	// - deque�� ���� ����
	// - �߰� ����/���� (BAD / BAD)
	// - ó��/�� ����/���� (Good / Good)
	// - �������� (Good)

	d[3] = 10;

	deque<int>::iterator it;

	return 0;
}