#pragma once
#include "Item.h"

// --------------------------------- CLASS
// --------------------------------- Equipment
class Equipment : public Item
{
private:
	bool isEquip;
	int dmg;
	int def;
	int hp;
	int mp;

public:

	Equipment()
	{
		this->SetIsEquip(false);
		this->SetItemPrice(0);
		this->SetItemNum(1);
		this->SetHp(0);
		this->SetMp(0);
		this->SetDmg(0);
		this->SetDef(0);
		this->SetItemName("NONE");
	}

	virtual void UseItem(Player* player);
	virtual void PrintItem();
	virtual void PrintItem(int _index);

	// get
	virtual bool GetIsEquip();
	virtual int GetDmg();
	virtual int GetDef();
	virtual int GetHp();
	virtual int GetMp();

	// set
	virtual void SetIsEquip(bool _isEquip);
	virtual void SetDmg(int _dmg);
	virtual void SetDef(int _def);
	virtual void SetHp(int _hp);
	virtual void SetMp(int _mp);
};