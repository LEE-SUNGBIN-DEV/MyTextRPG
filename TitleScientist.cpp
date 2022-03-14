#pragma once
#include "TitleScientist.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- TITLE SCIENTIST
void TitleScientist::UseItem(Player* player)
{
	setColor(VIOLET);
	// 장착중
	if (this->GetIsEquip())
	{
		this->SetIsEquip(false);
		player->SetMaxHp(player->GetMaxHp() - this->GetHp());
		player->SetHp(player->GetHp() - this->GetHp());
		player->SetMaxMp(player->GetMaxMp() - this->GetMp());
		player->SetMp(player->GetMp() - this->GetMp());
		player->SetTitle("");
		std::cout << "[ " << this->GetItemName() << " 타이틀을 장착 해제하였습니다. ]" << std::endl;
	}

	// 미장착
	else
	{
		this->SetIsEquip(true);
		player->SetMaxHp(player->GetMaxHp() + this->GetHp());
		player->SetHp(player->GetHp() + this->GetHp());
		player->SetMaxMp(player->GetMaxMp() + this->GetMp());
		player->SetMp(player->GetMp() + this->GetMp());
		player->SetTitle("(과학자)");
		std::cout << "[ " << this->GetItemName() << " 타이틀을 장착하였습니다. ]" << std::endl;
	}
}