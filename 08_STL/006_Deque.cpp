#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

// deque

// vector : 동적 배열
// list : 이중 연결 리스트
 
// 짬뽕된 형태가 deque
 
// deque : double-ended queue 데크
// [   ]
// [   ]
// [   ]


int main()
{
	// 시퀀스 컨테이너 (Sequence Container)
	// 데이터가 삽입 순서대로 나열되는 형태
	// vector / list / deque

	// vector와 마찬가지로 배열 기반으로 동작
	// 다만 메모리 할당 정책이 다르다

	// vector
	// [1  1  1] 
	// [1  1  1] 2  2] 늘리고 원래는 삭제

	// deque
	// [      3  3] 1동 몇호 느낌
	// [1  1  1  2] 2동 몇호
	// [2         ] 3동 몇호

	vector<int> v(3, 1);
	deque<int> d(3, 1);

	v.push_back(2);
	v.push_back(2);

	d.push_back(2);
	d.push_back(2);

	d.push_front(3);
	d.push_front(3);

	// - deque의 동작 원리
	// - 중간 삽입/삭제 (BAD / BAD)
	// - 처음/끝 삽입/삭제 (Good / Good)
	// - 임의접근 (Good)

	d[3] = 10;

	deque<int>::iterator it;

	return 0;
}