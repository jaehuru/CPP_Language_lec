#include <iostream>

using namespace std;

// �Լ� ������

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
//	// ���� üũ
//
//	for (int i = 0; i < itemCount; i++)
//	{
//		Item* item = &items[i];
//		if (item->_itemID == itemID)
//			return item;
//	}
//
//	return nullptr;
//} ��ȿ����

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

	// �ٱ��� �ּ�
	// pointer[ �ּ� ] -> �ּ�[    ]

	typedef int DATA;

	// 1) ������      *
	// 2) ���� �̸� ptr
	// 3) ������ Ÿ�� int
	DATA* ptr = &a;

	// �Լ�
	typedef int(FUNC_TYPE)(int, int);

	// 1) ������      *
	// 2) ���� �̸� fb
	// 3) ������ Ÿ�� �Լ� (���� int, int / ��ȯ�� int)
	FUNC_TYPE* fn;

	// �Լ� ������
	fn = Add;

	// �Լ��� �̸��� �Լ��� ���� �ּ� (�迭�� ����)
	int result = fn(1, 2); // �⺻ ����
	cout << result << endl;

	int result2 = (*fn)(1, 2); // �Լ� �����ʹ� *(���� ������) �پ �Լ� �ּ�!
	cout << result2 << endl;

	Item items[10] = {};
	items[3]._rarity = 2; // RARE
	Item* rareItem = FindItem(items, 10, IsRareItem, 2);


	return 0;
}