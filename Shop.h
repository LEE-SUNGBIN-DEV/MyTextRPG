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
		sellList.push_back(new Item("ȸ�� ����", 999, 50));
		sellList.push_back(new Item("���� ����", 999, 30));
	}

	~Shop()
	{
		std::cout << "[ ������ ���������ϴ�. ]" << std::endl;
	}

	// ���
	void PrintShopList();

	// ���
	void BuyItem(Player* player, int _sel);

	// Get
	std::vector<Item*> GetSellList();

	// Set

};