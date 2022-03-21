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
		this->SetItemName("ÄªÈ£: °úÇÐÀÚ");
		this->SetOriginName(this->GetItemName());
	}

	void UseItem(Player* player);
};