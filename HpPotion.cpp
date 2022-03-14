#include "HpPotion.h"
#include "Player.h"

void HpPotion::UseItem(Player* player)
{
    int value = 80;

    setColor(VIOLET);
    if (this->GetItemNum() > 0)
    {
        if (player->GetHp() <= (player->GetMaxHp() - value))
        {
            player->SetHp(player->GetHp() + value);
        }
        else
        {
            player->SetHp(player->GetMaxHp());
        }

        std::cout << this->GetItemName() << " 아이템을 사용하였습니다." << std::endl;
    }

    else
    {
        std::cout << "ERROR: NOT ENOUGH ITEM" << std::endl;
    }
}