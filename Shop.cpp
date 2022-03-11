#include "Shop.h"
#include "Item.h"
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
	// �ش� �������� �����ϱ⿡ ����� ���� ������
	if (player->GetMoney() >= this->sellList[_sel]->GetItemPrice())
	{
		player->SetMoney(player->GetMoney() - this->sellList[_sel]->GetItemPrice());

		this->sellList[_sel]->SetItemNum(this->sellList[_sel]->GetItemNum() - 1);

		player->AddItem(this->sellList[_sel]->GetItemName());
		
		std::cout << "[ " << this->sellList[_sel]->GetItemName() << "�� �����Ͽ����ϴ�. ]" << std::endl;
		std::cout << "[ �ܾ�: " << player->GetMoney() << " ]" << std::endl;
	}

	else
	{
		std::cout << "[ �ܾ��� �����մϴ�. ]" << std::endl;
	}

	return;
}

std::vector<Item*> Shop::GetSellList()
{
	return this->sellList;
}