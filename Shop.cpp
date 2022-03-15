#include "Shop.h"
#include "Item.h"
#include "HpPotion.h"
#include "MpPotion.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- SHOP

void Shop::PrintShopList()
{
	for (int i = 0; i < this->sellList.size(); i++)
	{
		this->sellList[i]->PrintItem(i);
	}

	return;
}
void Shop::BuyItem(Player* player, int _sel)
{
	setColor(SKYBLUE);
	// 해당 아이템을 구매하기에 충분한 돈이 있으면
	if (player->GetGold() >= this->sellList[_sel]->GetItemPrice())
	{
		player->SetGold(player->GetGold() - this->sellList[_sel]->GetItemPrice());

		this->sellList[_sel]->SetItemNum(this->sellList[_sel]->GetItemNum() - 1);

		if (this->sellList[_sel]->GetItemName() == "체력 물약")
		{
			player->AddItem(new HpPotion());
		}
		
		else if (this->sellList[_sel]->GetItemName() == "마나 물약")
		{
			player->AddItem(new MpPotion());
		}
		std::cout << " [ " << this->sellList[_sel]->GetItemName() << "을 구매하였습니다. ]" << std::endl;
		std::cout << " [ 잔액: " << player->GetGold() << " ]" << std::endl;
	}

	else
	{
		std::cout << " [ 잔액이 부족합니다. ]" << std::endl;
	}

	return;
}
void Shop::AddItem(Item* _item)
{
	this->sellList.push_back(_item);
}
std::vector<Item*> Shop::GetSellList()
{
	return this->sellList;
}