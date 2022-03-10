#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

class Item;
class Player;

class Shop
{
private:
	std::vector<Item*> sellList;

public:

	Shop()
	{
		sellList.push_back(new Item("회복 물약", 999, 50));
		sellList.push_back(new Item("마나 물약", 999, 30));
	}

	~Shop()
	{
		std::cout << "[ 상점이 무너졌습니다. ]" << std::endl;
	}

	// 출력
	void PrintShopList();

	// 기능
	void BuyItem(Player* player, int _sel);

	// Get
	std::vector<Item*> GetSellList();

	// Set

};