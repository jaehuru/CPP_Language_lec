#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// delete (������ �Լ�)

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
		// ���� ����
		k1 = k;
	}
};


int main()
{
	Knight k1;
	Knight k2;

	// ���� ������
	// k1 = k2;

	//Admin admin;
	//admin.CopyKnight(k1);


	return 0;
}