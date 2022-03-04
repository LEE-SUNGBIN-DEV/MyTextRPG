#pragma once
#include <iostream>
#include <vector>
#include "Character.h"
#include "Item.h"

// 직업 목록
enum MyPlayerType
{
    ENUM_PLAYER_NONE,
    ENUM_PLAYER_KNIGHT,
    ENUM_PLAYER_MAGICIAN
};

struct UserInfo
{
    std::string userName;
    int userAge;
};

// --------------------------------- CLASS
// --------------------------------- PLAYER
class Player : public Character
{
private:
    UserInfo userInfo;
    std::vector<Item> userInventory;
    std::string className;
    int playerClass;
    int dmg;
    int def;
    int exp;

public:
    // 생성자
    Player()
    {
        this->userInfo.userName = "NONE";
        this->userInfo.userAge = 0;
        this->dmg = 0;
        this->def = 0;
        this->exp = 0;
    }

    Player(int classSel)
    {
        switch (classSel)
        {
        case 1:
            this->className = "KNIGHT";
            this->playerClass = ENUM_PLAYER_KNIGHT;
            this->userInfo.userName = "NONE";
            this->userInfo.userAge = 0;
            this->dmg = 10;
            this->def = 10;
            this->exp = 0;
            break;
        
        case 2:
            this->className = "KNIGHT";
            this->playerClass = ENUM_PLAYER_KNIGHT;
            this->userInfo.userName = "NONE";
            this->userInfo.userAge = 0;
            this->dmg = 5;
            this->def = 5;
            this->exp = 0;
            break;
        }
    }

    // 공격 함수
    void Attack(Monster* monster);
    void QSkill(Monster* monster);
    void WShill(Monster* monster);
    void ESkill(Monster* monster);
    void RSkill(Monster* monster);

    // 기능 함수
    void PrintInfo();
    void AddItem(std::string _itemName, int _itemNum);

    // Get Info
    std::vector<Item> GetInventory();
    std::string GetItemName(int i);
    std::string GetUserName();
    std::string GetClassName();
    UserInfo GetUserInfo();
    int GetUserAge();
    int GetDmg();
    int GetExp();
    int GetItemNum(int i);
    int GetDef();
    int GetPlayerClass();

    // Set Info
    void SetUserInfo(std::string _name, int _age);
    void SetDmg(int _dmg);
    void SetExp(int _exp);
    void SetDef(int _def);
    void SetPlayerClass(int _sel);
};