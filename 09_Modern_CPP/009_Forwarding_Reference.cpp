#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 전달 참조(forwarding reference)

class Knight
{
public:
	Knight() { cout << "기본 생성자" << endl; }
	Knight(const Knight&) { cout << "복사 생성자" << endl; }
	Knight(Knight&&) noexcept { cout << "이동 생성자" << endl; }

};

void Test_RValueRef(Knight&& k) // 오른값 참조
{

}

void Test_Copy(Knight k)
{

}

template<typename T>
void Test_ForwardingRef(T&& param) // 전달 참조
{
	// 왼값 참조라면 복사
	// 오른값 참조라면 이동
	Test_Copy(forward<T>(param));
}

int main()
{
	// 보편 참조(universal reference)
	// 전달 참조(forwarding reference) C++17

	// && : &를 두번 -> 오른값 참조

	Knight k1;

	Test_RValueRef(move(k1)); // rvalue_cast

	//Test_ForwardingRef(k1);
	//Test_ForwardingRef(move(k1));

	auto&& k2 = k1;
	auto&& k3 = move(k1);

	// 공통점 : 형식 연역 (type deduction)이 일어날 때

	// 전달 참조를 구별하는 방법
	// ---------------------------------------

	Knight& k4 = k1; // 왼값 참조
	Knight&& k5 = move(k1); // 오른값 참조

	// 오른값 : 왼값이 아니다 = 단일식에서 벗아나면 사용 X
	// 오른값 참조 : 오른값만 참조 할 수 있는 참조 타입
	// Test_RValueRef(move(k5)); // k5 자체는 오른값 참조가 아니다

	Test_ForwardingRef(k1);
	Test_ForwardingRef(move(k1));


	return 0;
}