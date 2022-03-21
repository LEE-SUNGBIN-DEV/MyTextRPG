#pragma once
#include "Item.h"

// --------------------------------- CLASS
// --------------------------------- Equipment
class Equipment : public Item
{
private:
public:

	virtual void UseItem(Player* player);
	virtual void PrintItem();
	virtual void PrintItem(int _index);
};