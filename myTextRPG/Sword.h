#pragma once
#include "Equipment.h"

// --------------------------------- CLASS
// --------------------------------- SWORD
class Sword : public Equipment
{
private:

public:
	Sword()
	{
		this->SetItemType(ENUM_ITEM_EQUIP);
		this->SetIsEquip(false);
		this->SetItemPrice(50);
		this->SetItemNum(1);
		this->SetDmg(1);
		this->SetItemName("°Ë");
		this->SetOriginName(this->GetItemName());
	}

	Sword(int _itemNum) : Sword()
	{
		this->SetItemNum(_itemNum);
	}
};