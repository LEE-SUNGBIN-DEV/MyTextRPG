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
    // ������
    Knight()
    {
        this->SetMaxHp(250);
        this->SetMaxMp(100);
        this->SetHp(250);
        this->SetMp(100);
        this->SetTypeName("���");
        this->SetPlayerType(ENUM_PLAYER_KNIGHT);
        this->SetDmg(4);
        this->SetDef(8);
        this->SetSkillNameA("�转");
        this->SetSkillNameB("��ü��ȭ");
        this->SetSkillNameC("����");
    }

    ~Knight()
    {
        std::cout << "[ ��簡 �������ϴ�. ]" << std::endl;
    }

    // ���� �Լ�
    bool Attack(Monster* monster);
    bool SkillA(Monster* monster);
    bool SkillB(Monster* monster);
    bool SkillC(Monster* monster);
};