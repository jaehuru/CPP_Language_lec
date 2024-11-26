#include <iostream>

using namespace std;

struct StatInfo
{
	int hp;     // +0
	int attack; // +4
	int defence;// +8
};

// [매개변수][RET][지역변수(info)] [매개변수(&info)][RET][지역변수]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 5;
	info->defence = 1;
}

// [매개변수][RET][지역변수(info)] [매개변수(info)][RET][지역변수]
void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 5;
	info.defence = 1;
}

// 값을 수정하지 않는다면, 양쪽 다 일단 문제 없음

// 1) 값 전달 방식
// [매개변수][RET][지역변수(info)] [매개변수(info)][RET][지역변수)]
void PrintInfoByCopy(StatInfo info)
{
	cout << "--------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "--------------------" << endl;
}

// 2) 주소 전달 방식
// [매개변수][RET][지역변수(info)] [매개변수(&info)][RET][지역변수)]
void PrintInfoByPtr(StatInfo* info)
{
	cout << "--------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "--------------------" << endl;
}

// StatInfo 구조체가 대형 구조체라면?
// - (값 전달) 대형 값이 복사되는
// - (주소전달) 8바이트..!
// - (참조전달) 8바이트..!

// 값 전달처럼 편리하게 사용하고
// 주소 전달처럼 주소값을 이용해 알멩이를 건드리는
// 일석이조의 방식

void PrintInfoByRef(StatInfo& info)
{
	cout << "--------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "--------------------" << endl;
}

int main()
{	
	StatInfo info;

	StatInfo* pointer;
	pointer = &info;

	StatInfo& reference = info;

	// 포인터 vs 참조 세기의 대결

	// 성능 : 똑같음!

	// 편의성 : 참조 승!

	// 1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점만은 아니다.
	// 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줌.
	// 참조는 자연스럽게 모르고 지나칠 수도 있음.

	// const를 사용
	// 참고로 포인터도 const를 사용
	// * 기준으로 앞에 붙이느냐 뒤에 붙이느냐 차이가 있음
	// 별 뒤에 붙이면
	// info라는 바구니의 내용물(주소)을 바꿀 수 없음
	// info라는 주소값을 갖는 바구니 -> 이 주소값이 고정이다!

	// 별 앞에 붙이면
	// info가 '가르키고 있는' 바구니의 내용물을 바꿀 수 없음
	// '원격' 바구니의 내용물을 바꿀수 없음
	// info[ 주소값 ] 주소값[ 데이터 ]
	// info = &globalinfo; // 별뒤 막힘
	// info->hp = 10000; // 별앞 막힘

	// 2) 초기화 여부
	// 참조 타입은 바구니의 2번째 이름
	// -> 참조하는 대상이 없으면 안됨
	// 반면 포인터는 그냥 어떤~ 주소라는 의미
	// -> 대상이 실존하지 않을 수도 있음
	// 포인터에서 '없다'는 의미로 ? nullptr
	// 참조 타입은 이런 nullptr의 개념이 없다

	StatInfo* pointer = nullptr;

	//pointer = &info;

	PrintInfoByPtr(pointer);

	StatInfo& reference = info;

	PrintInfoByRef(reference);

	// 그래서 결론은?
	// 팀바이팀 정해진 답은 없다
	// 구글에선 포인터 선호
	// 언리얼 엔진에선 참조 선호
	// Rookiss 선호 스타일)
	// - 없는 경우 포인터
	// - 바뀌지 않고 읽는 용도 const ref&
	// 포인터로 사용하던걸 참조로 넘겨주려면?
	// pointer [ 주소(&info) ] -> ref, info[ 데이터 ]
	// Statinfo& ref = *pointer;

	PrintInfoByRef(*pointer);


	// 참조로 사용하던걸 포인터로 넘겨주려면?
	// pointer [ 주소 ] -> reference, info[ 데이터 ]

	PrintInfoByPtr(&reference); 
}