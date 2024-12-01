#include <iostream>
#include <vector>
#include <list>

using namespace std;

// List

// vector : ���� �迭

// list : ���Ḯ��Ʈ
// ���� / ���� / ����

// Node [ _data(4) _next(4/8) ] �����ͷ� ����Ǿ� ���� <-> [ _data(4) _next(4/8) ] <-> [ _data(4) _next(4/8) ] 
class Node
{
public:
	Node*   _next;
	Node*   _prev;
	int     _data;
};

// ����
// [1]��� -> [2] -> [3] -> [4] -> [5]

// ����!
// [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [ _Myhead : end() ] ���̳�� <-> ó������ ����

// ����
// [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> ó������ ����

int main()
{
	// list (���Ḯ��Ʈ)
	// - listd�� ���� ����
	// - �߰� ����/���� (Good)
	// ex) [1] <-> [2] <-> [100] <-> [3] <-> [4] <-> [5] ������ �����͸� ������� ����Ǿ� �ֱ⶧���� 
	
	// - ó��/�� ����/���� (Good / Good) ����������
	// - ���� ���� (BAD) (i��° �����ʹ� ��� �ֽ��ϱ�?) l[100000]x Ÿ��Ÿ�� �����ϱ� ������ �ʹ� ������ ����

	list<int>l;

	list<int>::iterator itRemember;

	for (int i = 0; i < 100; i++)
	{
		if (i == 50)
		{
			itRemember = l.insert(l.end(), i);
		}
		else
		{
			l.push_back(i);
		}
		l.push_back(i);
	}

	// li.push_front(10); ����
	int size = l.size();
	// l.capacity(); // ���� ��尳���̱� ������

	int first = l.front();
	int last = l.back();

	// l[1000000] = 10; // ��� �����͸� Ÿ�� �����ϴ� �κж����� ������ ����� ����

	//����Ʈ�� iterator���� ����� ���� �յ� ����� �ּҰ� ����Ǿ� ����
	list<int>::iterator itBegin = l.begin();
	list<int>::iterator itEnd = l.end();

	// list<int>::iterator it2 = itBegin + 10; // �Ұ���

	// list<int>::iterator itTest1 = --itBegin; �Ұ���
	list<int>::iterator itTest2 = --itEnd; // ���� 
	list<int>::iterator itTest3 = ++itEnd; // �Ұ���

	int* ptrBegin = &(l.front()); 
	int* ptrEnd = &(l.back());

	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << endl;
	}

	//l.insert(itBegin, 100);
	//l.erase(l.begin());
	//l.pop_front();
	//l.remove(10); // !!! 10�� ���� ���� ��常 �� ���Ű� �����ϱ� ������

	// * ���� ������ �ȵȴ�
	// * �߰� ����/���� ������ (?)
	// 50�� �ε����� �ִ� �����͸� ����!
	/*list<int>::iterator it = l.begin();
	for (int i = 0; i < 50; i++)
		++it;*/

	l.erase(itRemember);

	return 0;
}