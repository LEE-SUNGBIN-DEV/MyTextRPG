#pragma once
#include "Equipment.h"

// --------------------------------- CLASS
// --------------------------------- WAND
class SunGlasses : public Equipment
{
private:

public:
	SunGlasses()
	{
		this->SetItemType(ENUM_ITEM_EQUIP);
		this->SetIsEquip(false);
		this->SetItemPrice(0);
		this->SetItemNum(1);
		this->SetDef(3);
		this->SetItemName("������ ���۶�");
	}
};