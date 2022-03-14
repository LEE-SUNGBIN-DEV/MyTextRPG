#pragma once
#include "Equipment.h"

// --------------------------------- CLASS
// --------------------------------- WAND
class TitleScientist : public Equipment
{
private:

public:
	TitleScientist()
	{
		this->SetItemType(ENUM_ITEM_EQUIP);
		this->SetIsEquip(false);
		this->SetItemPrice(0);
		this->SetItemNum(1);
		this->SetHp(50);
		this->SetMp(50);
		this->SetItemName("칭호: 과학자");
	}

	void UseItem(Player* player);
};