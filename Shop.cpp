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
	if (player->GetGold() >= this->sellList[_sel]->GetItemPrice())
	{
		player->SetGold(player->GetGold() - this->sellList[_sel]->GetItemPrice());

		this->sellList[_sel]->SetItemNum(this->sellList[_sel]->GetItemNum() - 1);

		player->AddItem(this->sellList[_sel]->GetItemName());
		
		std::cout << "[ " << this->sellList[_sel]->GetItemName() << "�� �����Ͽ����ϴ�. ]" << std::endl;
		std::cout << "[ �ܾ�: " << player->GetGold() << " ]" << std::endl;
	}

	else
	{
		std::cout << "[ �ܾ��� �����մϴ�. ]" << std::endl;
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