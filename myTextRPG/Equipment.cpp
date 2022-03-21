#include "Equipment.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- EQUIPMENT
// 출력
void Equipment::PrintItem()
{
	setColor(SKYBLUE);
	std::cout << "--------------------------------" << std::endl;
	std::cout << " [" << this->GetItemName() << "] "
		<< "[ 수량: " << this->GetItemNum() << "] ";
	if (this->GetIsEquip())
	{
		std::cout << "[ 장착중 ]" << std::endl;
	}
	else
	{
		std::cout << "[ 미장착중 ]" << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
}
void Equipment::PrintItem(int _index)
{
	setColor(SKYBLUE);
	std::cout << "--------------------------------" << std::endl;
	std::cout << " [ 슬롯 번호: " << _index << "] "
		<< "[" << this->GetItemName() << "] "
		<< "[ 수량: " << this->GetItemNum() << "] ";
	if (this->GetIsEquip())
	{
		std::cout << "[ 장착중 ]" << std::endl;
	}
	else
	{
		std::cout << "[ 미장착중 ]" << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
}

// 기능 함수
void Equipment::UseItem(Player* player)
{
	setColor(SKYBLUE);
	// 장착중
	if (this->GetIsEquip())
	{
		this->SetIsEquip(false);
		player->SetDmg(player->GetDmg() - this->GetDmg());
		player->SetDef(player->GetDef() - this->GetDef());
		player->SetMaxHp(player->GetMaxHp() - this->GetHp());
		player->SetHp(player->GetHp() - this->GetHp());
		player->SetMaxMp(player->GetMaxMp() - this->GetMp());
		player->SetMp(player->GetMp() - this->GetMp());
		std::cout << " [ " << this->GetItemName() << "아이템을 장착 해제하였습니다. ]" << std::endl;
	}

	// 미장착
	else
	{
		this->SetIsEquip(true);
		player->SetDmg(player->GetDmg() + this->GetDmg());
		player->SetDef(player->GetDef() + this->GetDef());
		player->SetMaxHp(player->GetMaxHp() + this->GetHp());
		player->SetHp(player->GetHp() + this->GetHp());
		player->SetMaxMp(player->GetMaxMp() + this->GetMp());
		player->SetMp(player->GetMp() + this->GetMp());
		std::cout << " [ " << this->GetItemName() << "아이템을 장착하였습니다. ]" << std::endl;
	}
}
