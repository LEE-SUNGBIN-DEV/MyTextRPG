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
		this->SetItemType(ENUM_ITEM_POTION);
		this->SetItemPrice(20);
		this->SetItemName("마나 물약");
		this->SetOriginName(this->GetItemName());
	}

	MpPotion(int _itemNum) : MpPotion()
	{
		this->SetItemNum(_itemNum);
	}

	void UseItem(Player* player);
};