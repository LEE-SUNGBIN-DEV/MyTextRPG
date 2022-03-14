#pragma once
#include <iostream>
#include <string>
#include <vector>

// --------------------------------- CLASS
// --------------------------------- SHOP
class Item;
class Player;

class Shop
{
private:
	std::vector<Item*> sellList;

public:
	Shop()
	{
	}

	~Shop()
	{
		std::cout << "[ ������ ���������ϴ�. ]" << std::endl;
	}

	// ���
	void PrintShopList();

	// ���
	void BuyItem(Player* player, int _sel);
	void AddItem(Item* _item);

	// Get
	std::vector<Item*> GetSellList();

	// Set

};