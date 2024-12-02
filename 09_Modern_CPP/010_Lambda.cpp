#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 람다(lambda)

// 함수 객체를 빠르게 만드는 문법

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable
};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item() 
	{

	}

	Item(int itemID, Rarity rarity, ItemType type) :
		_itemID(itemID),
		_rarity(rarity),
		_type(type)
	{

	}

public:
	int _itemID = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;
};


int main()
{
	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

	// 람다 = 함수 객체를 손쉽게 만드는 문법
	// 람다 자체로 C++11에 '새로운' 기능이 들어간 것은 아니다
	{
		struct IsUniqueItem
		{
			bool operator()(Item& item) { return item._rarity == Rarity::Unique; }
		};

		// 클로저 (closure) = 람다에 의해 만들어진 실행시점 객체
		auto isUniqueLambda = [](Item& item) { return item._rarity == Rarity::Unique; }; // 람다 표현식(lambda expression)

		auto findIt = find_if(v.begin(), v.end(), [](Item& item) { return item._rarity == Rarity::Unique; });

		if (findIt != v.end())
			cout << "아이템 ID : " << findIt->_itemID << endl;
	}

	{
		struct FindItem
		{
			FindItem(int itemID, Rarity rarity, ItemType type) : 
				_itemID(itemID),
				_rarity(rarity),
				_type(type)
			{

			}

			bool operator()(Item& item) { return item._itemID == _itemID && item._rarity == _rarity && item._type == _type; }

			int _itemID;
			Rarity _rarity;
			ItemType _type;
		};

		int itemID = 4;
		Rarity rarity = Rarity::Unique;
		ItemType type = ItemType::Weapon;


		// [ ] 캡처(capture) : 함수 객체 내부의 변수를 저장하는 개념과 유사
		// 스냅샷을 찍는다고 이해
		// 기본 캡처 모드 : 복사 방식(=) 참조 방식(&)
		// 변수마다 캡처 모드를 지정해서 사용 가능 : 값 방식(name), 참조 방식(&name)

		auto findByItemIDLambda = [=](Item& item) { return item._itemID == itemID; }; // 람다 표현식(lambda expression)
		auto findByItem = [itemID, rarity, type](Item& item) { return item._itemID == itemID && item._rarity == rarity && item._type == type; }; // 람다 표현식(lambda expression)

		itemID = 10;
		
		auto findIt = find_if(v.begin(), v.end(), findByItem);

		if (findIt != v.end())
			cout << "아이템 ID : " << findIt->_itemID << endl;
	}

	{
		class Knight
		{
		public:
			auto ResetHPJob()
			{
				auto f = [this]() { this->_hp = 200; };

				return f;
			}

		public:
			int _hp = 100;
		};

		Knight* k = new Knight();
		auto job = k->ResetHPJob();
		delete k;
		job();
	}
	//[캡처](인자값) { 구현부 }
	return 0;
}