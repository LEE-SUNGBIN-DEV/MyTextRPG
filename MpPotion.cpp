#include "MpPotion.h"
#include "Player.h"

void MpPotion::UseItem(Player* player)
{
    int value = 50;

    if (this->GetItemNum() > 0)
    {
        player->SetMp(player->GetMp() + value);
        std::cout << this->GetItemName() << " �������� ����Ͽ����ϴ�." << std::endl;
    }

    else
    {
        std::cout << "ERROR: NOT ENOUGH ITEM" << std::endl;
    }
}