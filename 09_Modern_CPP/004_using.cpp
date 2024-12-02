#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// using

typedef vector<int>::iterator VecIt;

typedef int ID;
using ID2 = int;

// 1) 직관성
typedef void (*MyFunc)();
using MyFunc2 = void(*)();

// 2) 템플릿
template<typename T>
using List = vector<T>;

template<typename T>
struct List2
{
	typedef list<T> type;
};

int main()
{
	ID playerID = 0;

	List<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);

	List2<int>::type li2;

	return 0;
}