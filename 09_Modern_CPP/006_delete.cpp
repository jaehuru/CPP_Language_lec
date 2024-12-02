#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// delete (삭제된 함수)

class Knight
{
public:
	void operator=(const Knight& k) = delete;

private:
	int _hp = 100;
};

class Admin
{
public:
	void CopyKnight(const Knight& k)
	{
		Knight k1;
		// 복사 연산
		k1 = k;
	}
};


int main()
{
	Knight k1;
	Knight k2;

	// 복사 연산자
	// k1 = k2;

	//Admin admin;
	//admin.CopyKnight(k1);


	return 0;
}