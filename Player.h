#pragma once
#include <iostream>
#include "Character.h"

struct UserInfo
{
    std::string userName;
    int userAge;

    UserInfo()
    {
        userName = "NONE";
        userAge = 0;
    }
};
// --------------------------------- CLASS
// --------------------------------- PLAYER
class Player : public Character
{
private:
    UserInfo userInfo;
    int dmg;
    int exp;

public:
    // 생성자
    Player()
    {
        this->dmg = 2;
        this->exp = 0;
        this->userInfo.userAge = 0;
        this->userInfo.userName = "NONE";
    }

    // 기능 함수
    void PrintInfo();

    // Get Info
    UserInfo GetUserInfo();
    int GetDmg();
    int GetExp();

    // Set Info
    void SetUserInfo(std::string _name, int _age);
    void SetDmg(int _dmg);
    void SetExp(int _exp);
};