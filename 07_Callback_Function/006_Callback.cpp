#include <iostream>

using namespace std;

// �ݹ� (Callback)

class Item
{
public:

public:
	int _itemID = 0;
	int _rarity = 0;
	int _ownerID = 0;

};


class FindByOwnerID
{
public:
	bool operator()(const Item* item)
	{
		return (item->_ownerID == _ownerID);
	}

public:
	int _ownerID;
};

class FindByRarity
{
public:
	bool operator()(const Item* item)
	{
		return (item->_rarity >= _rarity);
	}

public:
	int _rarity;
};

template<typename T>
Item* FindItem(Item items[], int itemCount, T selector)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		
		if (selector(item))
			return item;
	}

	return nullptr;
}

int main()
{
	// �Լ� ������ + �Լ� ��ü + ���ø�
	// �ݹ� (Callback) : �ٽ� ȣ���ϴ�? ������ ȣ���ϴ�?

	// ������ ���鶧 �̷� �ݹ��� ������ ���� �����Ѵ�.
	// ex) MoveTask �ǽ� ��

	// � ��Ȳ�� �Ͼ�� -> �� ����� ȣ������
	// ex) UI ��ų ��ư�� ������ -> ��ų�� ���� �Լ��� ȣ��

	Item items[10];
	items[3]._ownerID = 100;
	items[8]._rarity = 2;

	FindByOwnerID functor1;
	functor1._ownerID = 100;

	FindByRarity functor2;
	functor2._rarity = 1;

	Item* item1 = FindItem(items, 10, functor1);
	Item* item2 = FindItem(items, 10, functor2);

	return 0;
}