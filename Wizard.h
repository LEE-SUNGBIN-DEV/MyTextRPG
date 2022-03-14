#pragma once
#include <iostream>
#include <vector>
#include "Item.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- WIZARD
class Monster;

class Wizard : public Player
{
private:

public:
    // 생성자
    Wizard()
    {
        this->SetMaxHp(150);
        this->SetMaxMp(300);
        this->SetHp(150);
        this->SetMp(300);
        this->SetTypeName("마법사");
        this->SetPlayerType(ENUM_PLAYER_WIZARD);
        this->SetDmg(8);
        this->SetDef(4);
        this->SetSkillNameA("파이어 볼");
        this->SetSkillNameB("아이스 스피어");
        this->SetSkillNameC("메테오");
    }

    ~Wizard()
    {
        std::cout << "[ 마법사가 떠났습니다. ]" << std::endl;
    }

    // 공격 함수
    bool Attack(Monster* monster);
    bool SkillA(Monster* monster);
    bool SkillB(Monster* monster);
    bool SkillC(Monster* monster);

};