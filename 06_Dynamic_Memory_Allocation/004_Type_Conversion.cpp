#include <iostream>

using namespace std;

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2
};

class Knight
{

public:
	int _hp = 0;

};

class Item
{
public:

	Item()
	{
		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "Item(int itemType)" << endl;
	}

	Item(const Item& item)
	{
		cout << "Item(const Item& item)" << endl;
	}

	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Item" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbld = 0;
	char _dummy[4096] = {}; // �̷� ���� ������� ���� �������

};

class Weapon : public Item
{

public:
	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
		_damage = rand() % 100;
	}

	~Weapon()
	{
		cout << "~Weapon()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Weapon" << endl;
	}

public:
	int _damage = 0;

};

class Armor : public Item
{

public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
	}

	~Armor()
	{
		cout << "~Armor()" << endl;
	}

public:
	int _defence = 0;

};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{
	item->Test();
}

int main()
{
	// �������� ���� Ŭ���� ������ ������ ��ȯ �׽�Ʈ
	{
		// Stack [ �ּ� ] -> Heap [ _hp ]

		Knight* knight = new Knight();

		// ��������� OK

		// Stack [ �ּ� ]

		/*Item* item = (Item*)knight;

		item->_itemType = 2;

		item->_itemDbld = 1;*/

		delete knight;
	}

	// �θ� -> �ڽ� ��ȯ �׽�Ʈ
	{
		Item* item = new Item();

		//Weapon* weapon = (Weapon*)item; �߸��� �޸𸮸� �ǵ�°Ŷ� ������

		//weapon->_damage = 10;

		delete item;
	}

	// �ڽ� -> �θ� ��ȯ �׽�Ʈ
	{
		Weapon* weapon = new Weapon();

		// �Ͻ������� �ȴ�!

		Item* item = weapon;
		TestItemPtr(item);
		delete weapon;
	}

	// ��������� Ÿ�� ��ȯ�� ���� �׻� �׻� �����ؾ� �Ѵ�!

	// �Ͻ������� �� ���� �����ϴ�?

	// -> ��� ��������� Ÿ�� ��ȯ(ĳ����)�� ���ϸ� �Ǵ°� �ƴѰ�?

	Item* inventory[20] = {};

	srand((unsigned int)time(nullptr));

	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2; // 0~1

		switch (randValue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;
		case 1:
			inventory[i] = new Armor();
			break;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];

		if (item == nullptr)
			continue;

		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}

	}

	// ************************ �ſ� �߿� ****************************

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];

		if (item == nullptr)
			continue;
		delete item;
	}

	// [���]
	
	// - ������ vs �Ϲ� Ÿ�� : ���̸� ��������

	// - ������ ������ Ÿ�� ��ȯ(ĳ����)�� �� ���� �ſ� �ſ� �����ؾ� �Ѵ�!

	// - �θ�-�ڽ� ���迡�� �θ� Ŭ������ �Ҹ��ڿ��� ��������� virtual�� ������!!!
	// ��� ���迡 ���ؼ� �Լ��� ������ �غ��� � �Ѿ길 ��� ������ �Ǳ� ������ �����Լ����̺��� ����� �Ǹ鼭 ���� ��ü�� � ��� ��������Ŀ� ���� �� �Լ��� ã�Ƽ� ȣ�����ش�

	return 0;
}

