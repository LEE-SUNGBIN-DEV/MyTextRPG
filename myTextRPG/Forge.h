#pragma once
#include <iostream>
#include <string>
#include <vector>

// --------------------------------- CLASS
// --------------------------------- FORGE
class Equipment;
class Player;

class Forge
{
private:
	std::vector<Equipment*> sellList;
	int honingPrice;

public:
	Forge()
	{
		this->SetHoningPrice(25);
	}

	~Forge()
	{
		std::cout << "[ ���尣�� ���������ϴ�. ]" << std::endl;
	}

	// ���
	void PrintShopList();

	// ���
	void BuyItem(Player* player, int _sel);
	void AddItem(Equipment* _item);
	void HoningItem(Player* player, int _sel);

	// Get
	std::vector<Equipment*> GetSellList();
	int GetHoningPrice();

	// Set
	void SetHoningPrice(int _honingPrice);
};