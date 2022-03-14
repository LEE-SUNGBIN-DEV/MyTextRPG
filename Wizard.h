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
    // ������
    Wizard()
    {
        this->SetMaxHp(150);
        this->SetMaxMp(300);
        this->SetHp(150);
        this->SetMp(300);
        this->SetTypeName("������");
        this->SetPlayerType(ENUM_PLAYER_WIZARD);
        this->SetDmg(8);
        this->SetDef(4);
        this->SetSkillNameA("���̾� ��");
        this->SetSkillNameB("���̽� ���Ǿ�");
        this->SetSkillNameC("���׿�");
    }

    ~Wizard()
    {
        std::cout << "[ �����簡 �������ϴ�. ]" << std::endl;
    }

    // ���� �Լ�
    bool Attack(Monster* monster);
    bool SkillA(Monster* monster);
    bool SkillB(Monster* monster);
    bool SkillC(Monster* monster);

};