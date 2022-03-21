#pragma once
#include <iostream>
#include <vector>
#include "Item.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- KNIGHT
class Monster;

class Knight : public Player
{
private:

public:
    // 생성자
    Knight()
    {
        this->SetMaxHp(250);
        this->SetMaxMp(100);
        this->SetHp(250);
        this->SetMp(100);
        this->SetTypeName("기사");
        this->SetPlayerType(ENUM_PLAYER_KNIGHT);
        this->SetDmg(4);
        this->SetDef(8);
        this->SetSkillNameA("배쉬");
        this->SetSkillNameB("신체강화");
        this->SetSkillNameC("심판");
    }

    ~Knight()
    {
        std::cout << "[ 기사가 떠났습니다. ]" << std::endl;
    }

    // 공격 함수
    bool Attack(Monster* monster);
    bool SkillA(Monster* monster);
    bool SkillB(Monster* monster);
    bool SkillC(Monster* monster);
};