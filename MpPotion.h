#pragma once
#include "Item.h"

// --------------------------------- CLASS
// --------------------------------- MP POTION
class MpPotion : public Item
{
private:

public:

	MpPotion()
	{
		this->SetItemPrice(20);
		this->SetItemName("���� ����");
	}

	MpPotion(int _itemNum) : MpPotion()
	{
		this->SetItemNum(_itemNum);
	}

	void UseItem(Player* player);
};