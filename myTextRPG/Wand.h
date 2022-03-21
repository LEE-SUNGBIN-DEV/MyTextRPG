#pragma once
#include "Equipment.h"

// --------------------------------- CLASS
// --------------------------------- WAND
class Wand : public Equipment
{
private:

public:
	Wand()
	{
		this->SetItemType(ENUM_ITEM_EQUIP);
		this->SetIsEquip(false);
		this->SetItemPrice(0);
		this->SetItemNum(1);
		this->SetDmg(3);
		this->SetItemName("럭스의 지팡이");
		this->SetOriginName(this->GetItemName());
	}
};