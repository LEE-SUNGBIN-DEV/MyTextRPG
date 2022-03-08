#pragma once
#include <iostream>
#include <string>
#include <vector>

class Item;
class Player;

class Shop
{
private:
	std::vector<Item*> sellList;

public:

	// ±â´É
	void BuyItem(Player* player);

	// Get
	std::vector<Item*> GetSellList();

	// Set

};