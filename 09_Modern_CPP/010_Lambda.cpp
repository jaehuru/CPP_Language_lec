#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// ����(lambda)

// �Լ� ��ü�� ������ ����� ����

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

	// ���� = �Լ� ��ü�� �ս��� ����� ����
	// ���� ��ü�� C++11�� '���ο�' ����� �� ���� �ƴϴ�
	{
		struct IsUniqueItem
		{
			bool operator()(Item& item) { return item._rarity == Rarity::Unique; }
		};

		// Ŭ���� (closure) = ���ٿ� ���� ������� ������� ��ü
		auto isUniqueLambda = [](Item& item) { return item._rarity == Rarity::Unique; }; // ���� ǥ����(lambda expression)

		auto findIt = find_if(v.begin(), v.end(), [](Item& item) { return item._rarity == Rarity::Unique; });

		if (findIt != v.end())
			cout << "������ ID : " << findIt->_itemID << endl;
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


		// [ ] ĸó(capture) : �Լ� ��ü ������ ������ �����ϴ� ����� ����
		// �������� ��´ٰ� ����
		// �⺻ ĸó ��� : ���� ���(=) ���� ���(&)
		// �������� ĸó ��带 �����ؼ� ��� ���� : �� ���(name), ���� ���(&name)

		auto findByItemIDLambda = [=](Item& item) { return item._itemID == itemID; }; // ���� ǥ����(lambda expression)
		auto findByItem = [itemID, rarity, type](Item& item) { return item._itemID == itemID && item._rarity == rarity && item._type == type; }; // ���� ǥ����(lambda expression)

		itemID = 10;
		
		auto findIt = find_if(v.begin(), v.end(), findByItem);

		if (findIt != v.end())
			cout << "������ ID : " << findIt->_itemID << endl;
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
	//[ĸó](���ڰ�) { ������ }
	return 0;
}