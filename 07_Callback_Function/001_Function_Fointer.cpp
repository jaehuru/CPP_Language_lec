#include <iostream>

using namespace std;

// 함수 포인터

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Item
{

public:
	Item() :
		_itemID(0), _rarity(0), _ownerID(0)
	{

	}

public:
	int _itemID;
	int _rarity;
	int _ownerID;

};

//Item* FindItemByItemID(Item items[], int itemCount, int itemID)
//{
//	// 안전 체크
//
//	for (int i = 0; i < itemCount; i++)
//	{
//		Item* item = &items[i];
//		if (item->_itemID == itemID)
//			return item;
//	}
//
//	return nullptr;
//} 비효율적

typedef bool (ITEM_SELECTOR)(Item*, int);

Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector, int value)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		if (selector(item, value))
			return item;
	}

	return nullptr;
}

bool IsRareItem(Item* item, int value)
{
	return item->_rarity >= 2;
}

bool IsOwnerItem(Item* item, int ownerID)
{
	return item->_ownerID == ownerID;
}

int main()
{
	int a = 10;

	// 바구니 주소
	// pointer[ 주소 ] -> 주소[    ]

	typedef int DATA;

	// 1) 포인터      *
	// 2) 변수 이름 ptr
	// 3) 데이터 타입 int
	DATA* ptr = &a;

	// 함수
	typedef int(FUNC_TYPE)(int, int);

	// 1) 포인터      *
	// 2) 변수 이름 fb
	// 3) 데이터 타입 함수 (인자 int, int / 반환은 int)
	FUNC_TYPE* fn;

	// 함수 포인터
	fn = Add;

	// 함수의 이름은 함수의 시작 주소 (배열과 유사)
	int result = fn(1, 2); // 기본 문법
	cout << result << endl;

	int result2 = (*fn)(1, 2); // 함수 포인터는 *(접근 연사자) 붙어도 함수 주소!
	cout << result2 << endl;

	Item items[10] = {};
	items[3]._rarity = 2; // RARE
	Item* rareItem = FindItem(items, 10, IsRareItem, 2);


	return 0;
}