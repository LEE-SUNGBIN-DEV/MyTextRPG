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
	// �ش� �������� �����ϱ⿡ ����� ���� ������
	if (player->GetGold() >= this->sellList[_sel]->GetItemPrice())
	{
		player->SetGold(player->GetGold() - this->sellList[_sel]->GetItemPrice());

		this->sellList[_sel]->SetItemNum(this->sellList[_sel]->GetItemNum() - 1);

		if (this->sellList[_sel]->GetItemName() == "��")
		{
			player->AddItem(new Sword());
		}

		std::cout << " [ " << this->sellList[_sel]->GetItemName() << "�� �����Ͽ����ϴ�. ]" << std::endl;
		std::cout << " [ �ܾ�: " << player->GetGold() << " ]" << std::endl;
	}

	else
	{
		std::cout << " [ �ܾ��� �����մϴ�. ]" << std::endl;
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
	// ���� Ȯ��
	if (player->GetIsEquip(_sel))
	{
		std::cout << " [ " << player->GetItemName(_sel) << " ������ �������ּ���. ]" << std::endl;
		return;
	}
	// ��� Ȯ��
	if (player->GetGold() >= this->GetHoningPrice())
	{
		player->SetGold(player->GetGold() - this->GetHoningPrice());
		std::cout << " [ " << player->GetItemName(_sel) << "�� ��ȭ�մϴ�. ]" << std::endl;
		
		if (randNum > 50)
		{
			std::cout << " [ ��� ����!! ]" << std::endl;
			player->SetItemHoningLevel(player->GetItemHoningLevel(_sel) + 1, _sel);
			player->SetItemDmg(player->GetItemDmg(_sel) + 1, _sel);
			player->SetItemName(player->GetOriginName(_sel) + " +" + std::to_string(player->GetItemHoningLevel(_sel)), _sel);
		}
		else
		{
			std::cout << " [ ��� ���� �Ф� ]" << std::endl;
		}
		std::cout << " [ �ܾ�: " << player->GetGold() << " ]" << std::endl;
	}

	else
	{
		std::cout << " [ ��� ����� �����մϴ�. ]" << std::endl;
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