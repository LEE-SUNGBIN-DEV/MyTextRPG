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
		this->SetItemType(ENUM_ITEM_POTION);
		this->SetItemPrice(30);
		this->SetItemName("체력 물약");
		this->SetOriginName(this->GetItemName());
	}

	HpPotion(int _itemNum) : HpPotion()
	{
		this->SetItemNum(_itemNum);
	}

	void UseItem(Player* player);
};