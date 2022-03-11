#include "HpPotion.h"
#include "Player.h"

void HpPotion::UseItem(Player* player)
{
    int value = 50;

    if (this->GetItemNum() > 0)
    {
        player->SetHp(player->GetHp() + value);
        std::cout << this->GetItemName() << " 아이템을 사용하였습니다." << std::endl;
    }

    else
    {
        std::cout << "ERROR: NOT ENOUGH ITEM" << std::endl;
    }
}