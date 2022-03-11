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