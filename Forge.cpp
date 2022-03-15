#include "Forge.h"
#include "Item.h"
#include "Sword.h"
#include "Player.h"
#include "Equipment.h"
#include <random>

// --------------------------------- CLASS
// --------------------------------- SHOP

void Forge::PrintShopList()
{
	for (int i = 0; i < this->sellList.size(); i++)
	{
		this->sellList[i]->PrintItem(i);
	}

	return;
}
void Forge::BuyItem(Player* player, int _sel)
{
	setColor(SKYBLUE);
	// 해당 아이템을 구매하기에 충분한 돈이 있으면
	if (player->GetGold() >= this->sellList[_sel]->GetItemPrice())
	{
		player->SetGold(player->GetGold() - this->sellList[_sel]->GetItemPrice());

		this->sellList[_sel]->SetItemNum(this->sellList[_sel]->GetItemNum() - 1);

		if (this->sellList[_sel]->GetItemName() == "검")
		{
			player->AddItem(new Sword());
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
void Forge::HoningItem(Player* player, int _sel)
{
	int randNum;
	std::random_device rd;

	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 99);

	randNum = dis(gen);

	setColor(SKYBLUE);
	// 장착 확인
	if (player->GetIsEquip(_sel))
	{
		std::cout << " [ " << player->GetItemName(_sel) << " 장착을 해제해주세요. ]" << std::endl;
		return;
	}
	// 비용 확인
	if (player->GetGold() >= this->GetHoningPrice())
	{
		player->SetGold(player->GetGold() - this->GetHoningPrice());
		std::cout << " [ " << player->GetItemName(_sel) << "을 강화합니다. ]" << std::endl;
		
		if (randNum > 50)
		{
			std::cout << " [ 재련 성공!! ]" << std::endl;
			player->SetItemHoningLevel(player->GetItemHoningLevel(_sel) + 1, _sel);
			player->SetItemDmg(player->GetItemDmg(_sel) + 1, _sel);
			player->SetItemName(player->GetOriginName(_sel) + " +" + std::to_string(player->GetItemHoningLevel(_sel)), _sel);
		}
		else
		{
			std::cout << " [ 재련 실패 ㅠㅠ ]" << std::endl;
		}
		std::cout << " [ 잔액: " << player->GetGold() << " ]" << std::endl;
	}

	else
	{
		std::cout << " [ 재련 비용이 부족합니다. ]" << std::endl;
	}

	return;
}

void Forge::AddItem(Equipment* _item)
{
	this->sellList.push_back(_item);
}

// get
std::vector<Equipment*> Forge::GetSellList()
{
	return this->sellList;
}
int Forge::GetHoningPrice()
{
	return this->honingPrice;
}

// set
void Forge::SetHoningPrice(int _honingPrice)
{
	this->honingPrice = _honingPrice;
	return;
}