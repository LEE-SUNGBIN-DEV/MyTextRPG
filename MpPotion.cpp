#include "MpPotion.h"
#include "Player.h"

void MpPotion::UseItem(Player* player)
{
    int value = 50;

    setColor(SKYBLUE);
    if (this->GetItemNum() > 0)
    {
        if (player->GetMp() <= (player->GetMaxMp() - value))
        {
            player->SetMp(player->GetMp() + value);
        }
        else
        {
            player->SetMp(player->GetMaxMp());
        }

        std::cout << " [ " << this->GetItemName() << " 아이템을 사용하였습니다. ]" << std::endl;
    }

    else
    {
        std::cout << "ERROR: NOT ENOUGH ITEM" << std::endl;
    }
}