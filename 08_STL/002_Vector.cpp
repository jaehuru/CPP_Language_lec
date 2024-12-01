#include <iostream>
#include <vector>

using namespace std;

// 백터



int main()
{
	// STL (Standard Template Library)
	// 프로그래밍할 때 필요한 자료구조/알고리즘들을
	// 템플릿으로 제공하는 라이브러리

	// 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

	// vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)

	// 반복자(Iterator) : 포인터와 유사한 개념. 컨테이너의 원소(데이터)를 가르키고, 다음/이전 원소로 이동 가능
	vector<int>v(10);

	v.reserve(1000);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
		v[i] = i;

	//vector<int>::iterator it;
	//int* ptr;

	//it = v.begin();
	//ptr = &v[0];

	//cout << (*it) << endl;
	//cout << (*ptr) << endl;

	////int a = 1;
	//// int b = a++; // (b = 1, a = 2)
	//// int c = ++a; // (c = 2, a = 2)

	//it++;
	//++it;
	//ptr++;
	//++ptr;

	//it--;
	//--it;
	//ptr--;
	//--ptr;

	//it += 2;
	//it = it - 2;
	//ptr += 2;
	//ptr = ptr - 2;

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end(); // 쓰레기값이 들어있음

	// 더 복잡해보이는데?
	// 다른 컨테이너는 v[i]와 같은 인덱스 접근이 안 될 수도 있음
	// iterator는 vector뿐 아니라, 다른 컨테이너에도 공통적으로 있는 개념
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) // it++보다 아주 조금 성능이 좋다
	{
		cout << (*it) << endl;
	}

	int* ptrBegin = &v[0]; // v.begin()._Ptr;
	int* ptrEnd = ptrBegin + 10; // v.end()._Ptr;
	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
	{
		cout << (*ptr) << endl;
	}

	// const int*;
	// vector<int>::const_iterator cit1 = v.cbegin();
	// *cit1 = 100; 불가능

	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	{
		cout << (*it) << endl;
	}

	// 면접 단골 질문
	// - 중간 삽입/삭제 (BAD) // 뒤에 있는 데이터들을 복사하고 한칸씩 옮겨야하기 때문에 비효율적
	// - 처음/끝 삽입/삭제 (BAD / GOOD)
	// - 임의 접근 (Random Access)

	// vector = 동적 배열 = 동적으로 커지는 배열 = 배열
	// 원소가 하나의 메모리 블록에 연속하게 저장된다 !!!

	// [                   ]
	// [0][1][2][3][4][ ][ ]

	//v.push_back(1);
	//v.pop_back();
	// v.push_front()? 비효율적이기 때문에 없음

	// 3번째 데이터는 어디 있습니까?
	// v[2] = 3;

	//vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);
	//vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);
	//vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin()+4); //범위 삭제

	// 쭉~ 스캔을 하면서, 3이라는 데이터가 있으면 일괄 삭제하고 싶다
	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		int data = *it;
		if (data == 3)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}

	return 0;
}