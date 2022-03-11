#pragma once
#include "Item.h"

class Player;
// --------------------------------- CLASS
// --------------------------------- HP POTION
class HpPotion : public Item
{
private:

public:

	HpPotion()
	{
		this->SetItemPrice(30);
		this->SetItemName("ȸ�� ����");
	}

	HpPotion(int _itemNum) : HpPotion()
	{
		this->SetItemNum(_itemNum);
	}

	void UseItem(Player* player);
};