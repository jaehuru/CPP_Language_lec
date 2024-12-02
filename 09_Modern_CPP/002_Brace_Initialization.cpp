#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 중괄호 초기화 { }

class Knight
{
public:
	Knight()
	{

	}

	Knight(int a, int b)
	{
		cout << "인자 생성자" << endl;
	}


	Knight(initializer_list<int> li)
	{
		cout << "이니셜라이즈 리스트" << endl;
	}
};


int main()
{
	// 중괄호 초기화 { }
	int a = 0;
	int b(0);
	int c{ 0 };

	Knight k1;
	Knight k2 = k1; // 복사 생성자 (대입 연산자X)

	// Knight k3; // 기본 생성자
	// k3 = k1; // 대입 연산자
	Knight k3{ k2 };

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2(10, 1);
	int arr[] = { 1, 2, 3, 4 };

	// 중괄호 초기화
	// 1) vector 등 container와 잘 어울린다
	vector<int> v3{ 1, 2, 3, 4, 5, 7, 6, 7, 4, 3, 2 }; 
	vector<int> v4{ 1, 2 }; // 이니셜라이저 리스트가 우선순위라 조심

	// 2) 축소 변환 방지
	int x = 0;
	// double y{ x };

	// 3) Bonus
	Knight k4{};

	Knight k5{ 1, 2, 3, 4, 5 };

	Knight k6{ 1, 2 }; // 이니셜라이저 리스트가 우선순위라 조심

	// 괄호 초기화 ()를 기본으로 간다
	// - 전통적인 C++ (거부감이 없음)
	// - vector 등 특이한 케이스에 대해서만 { } 사용
	
	// 중괄호 초기화 { }를 기본으로 간다
	// - 초기화 문법의 일치화
	// - 축소 변환 방지
	
	return 0;
}