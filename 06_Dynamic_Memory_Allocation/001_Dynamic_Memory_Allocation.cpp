#include <iostream>

using namespace std;

// 메모리 구조 복습

// - 실행할 코드가 저장되는 영역 -> 코드 영역
// - 전역(global)/정적(static) 변수 -> 데이터 영역
// - 지역 변수/매개 변수 -> 스택 영역
// - 동적 할당 -> 힙 영역

// 지금까지 데이터 영역/ 스택 영역 이용해서
// 이런 저런 프로그램을 잘 만들어 왔다!
// 굳이 새로운 영역이 필요할까?

// 실제 상황)
// - mmorpg 동접 1명~5만명, 몬스터 1마리~500만 마리
 
// - 몬스터 생성 이벤트 -> 5분동안 몬스터가 10배 많이 나옴

// - 스택 영역
// 함수가 끝나면 같이 정리되는 불안정한 메모리
// 잠시 함수에 매개변수 넘긴다거나, 하는 용도로 OK
// 메모리 영역
// 프로그램이 싱행되는 도중에는 '무조건' 사용되는

// 희망사항)
// - 필요할때만 사용하고, 필요없으면 반납할 수 있는!
// - 그러면서도 (스택과는 다르게) 우리가 생성/소멸 시점을 관리 할 수 있는!
// - 그런 아름다운 메모리 없나? -> HEAP

// 동적할당과 연관된 함수/연산자 : malloc / free, new / delete, new[] / delete[]

// malloc
// - 할당할 메모리 크기를 건내준다
// - 메모리 할당 후 시작 주소를 가르키는 포인터를 반환해준다. (메모리 부족 NULL)

// free
// - malloc (혹은 기타 calloc, realloc 등의 사촌) 을 통해 할당된 영역을 해제
// - 힙 관리자가 할당/미할당 여부를 구분해서 관리

// new / delete
// - c++에 추가됨
// - malloc/free 함수! new/delete는 연산자(oprerator)

// new[] / delete[]
// - 배열과 같이 n개 데이터를 같이 할당하려면?

// malloc/free vs new/delete
// - 사용 편의성 -> new/delete 승!
// - 타입에 상관없이 특정한 크기의 메모리 영역을 할당받으려면? malloc/free 승!

// 둘의 차이
// 함수와 연산자
// new/delete는 (생성타입이 클래스일 경우) 생성자/소멸자를 호출해준다! 중요

class Monster
{

public:
	Monster()
	{
		cout << "Monster()" << endl;
	}

	~Monster()
	{
		cout << "~Monster()" << endl;
	}

public:
	int _hp;
	int _x;
	int _y;

};

// Monster monster[500 * 10000];

int main()
{
	// 유저 영역 [메모장] [LoL] [곰플레이어]

	// ---------------------------------

	// 커널 영역 (Window 등의 핵심 코드)

	// 유저 영역) 운영체제에서 제공하는 API 호출
	// 커널 영역) 메모리 할당해서 건내줌

	// 유저 영역) ㄳㄳ 잘쓸게
	// [ ]

	// c++에서는 기본적으로 CRT(C런타임 라이브러리)의 [힙 관리자]를 통해 힙 영역 사용
	// 단, 정말 원한다면 우리가 직접 API를 통해 힙을 생성하고 관리할 수도 있음(mmorpg 서버 메모리 풀링)
	// void* 무엇일까
	// 타고 가면 void 뭐가 있는지 모르겠으니까 너가 적당히 변환해서 사용해라

	void* pointer = malloc(sizeof(Monster));

	Monster* m1 = (Monster*)pointer;
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	// 만약에 free하지 않으면 메모리 누수

	free(pointer);

	Monster* m2 = new Monster;
	m2->_hp = 100;
	m2->_x = 1;
	m2->_y = 2;
	delete m2;

	/*Monster* m3 = new Monster[5];
	m3->_hp = 100;
	m3->_x = 1;
	m3->_y = 2;

	Monster* m4 = (m3 + 1);
	m4->_hp = 100;
	m4->_x = 1;
	m4->_y = 2;
	delete[] m3;*/

	return 0;
}

