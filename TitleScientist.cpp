#pragma once
#include "TitleScientist.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- TITLE SCIENTIST
void TitleScientist::UseItem(Player* player)
{
	setColor(VIOLET);
	// ������
	if (this->GetIsEquip())
	{
		this->SetIsEquip(false);
		player->SetMaxHp(player->GetMaxHp() - this->GetHp());
		player->SetHp(player->GetHp() - this->GetHp());
		player->SetMaxMp(player->GetMaxMp() - this->GetMp());
		player->SetMp(player->GetMp() - this->GetMp());
		player->SetTitle("");
		std::cout << "[ " << this->GetItemName() << " Ÿ��Ʋ�� ���� �����Ͽ����ϴ�. ]" << std::endl;
	}

	// ������
	else
	{
		this->SetIsEquip(true);
		player->SetMaxHp(player->GetMaxHp() + this->GetHp());
		player->SetHp(player->GetHp() + this->GetHp());
		player->SetMaxMp(player->GetMaxMp() + this->GetMp());
		player->SetMp(player->GetMp() + this->GetMp());
		player->SetTitle("(������)");
		std::cout << "[ " << this->GetItemName() << " Ÿ��Ʋ�� �����Ͽ����ϴ�. ]" << std::endl;
	}
}