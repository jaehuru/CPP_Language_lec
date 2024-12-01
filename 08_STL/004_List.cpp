#include <iostream>
#include <vector>
#include <list>

using namespace std;

// List

// vector : 동적 배열

// list : 연결리스트
// 단일 / 이중 / 원형

// Node [ _data(4) _next(4/8) ] 포인터로 연결되어 있음 <-> [ _data(4) _next(4/8) ] <-> [ _data(4) _next(4/8) ] 
class Node
{
public:
	Node*   _next;
	Node*   _prev;
	int     _data;
};

// 단일
// [1]노드 -> [2] -> [3] -> [4] -> [5]

// 이중!
// [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [ _Myhead : end() ] 더미노드 <-> 처음노드와 연결

// 원형
// [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> 처음노드랑 연결

int main()
{
	// list (연결리스트)
	// - listd의 동작 원리
	// - 중간 삽입/삭제 (Good)
	// ex) [1] <-> [2] <-> [100] <-> [3] <-> [4] <-> [5] 노드들이 포인터를 기반으로 연결되어 있기때문에 
	
	// - 처음/끝 삽입/삭제 (Good / Good) 마찬가지로
	// - 입의 접근 (BAD) (i번째 데이터는 어디 있습니까?) l[100000]x 타고타고 가야하기 때문에 너무 느릴수 있음

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

	// li.push_front(10); 가능
	int size = l.size();
	// l.capacity(); // 없음 노드개념이기 때문에

	int first = l.front();
	int last = l.back();

	// l[1000000] = 10; // 계속 포인터를 타고 가야하는 부분때문에 느려서 기능이 없음

	//리스트의 iterator에는 노드의 값과 앞뒤 노드의 주소가 저장되어 있음
	list<int>::iterator itBegin = l.begin();
	list<int>::iterator itEnd = l.end();

	// list<int>::iterator it2 = itBegin + 10; // 불가능

	// list<int>::iterator itTest1 = --itBegin; 불가능
	list<int>::iterator itTest2 = --itEnd; // 가능 
	list<int>::iterator itTest3 = ++itEnd; // 불가능

	int* ptrBegin = &(l.front()); 
	int* ptrEnd = &(l.back());

	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << endl;
	}

	//l.insert(itBegin, 100);
	//l.erase(l.begin());
	//l.pop_front();
	//l.remove(10); // !!! 10의 값을 가진 노드만 쏙 제거가 가능하기 때문에

	// * 임의 접근이 안된다
	// * 중간 삽입/삭제 빠르다 (?)
	// 50번 인덱스에 있는 데이터를 삭제!
	/*list<int>::iterator it = l.begin();
	for (int i = 0; i < 50; i++)
		++it;*/

	l.erase(itRemember);

	return 0;
}