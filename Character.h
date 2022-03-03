#pragma once
#include <iostream>

// --------------------------------- CLASS
// --------------------------------- CHARACTER
class Character
{
public:
    std::string name;
    int hp;
    int mp;
    float moveSpeed;
    bool alive;

public:
    // 생성자
    Character()
    {
        this->name = "NONE";
        this->hp = 100;
        this->mp = 50;
        this->moveSpeed = 1.0f;
        this->alive = true;
    }

    // 기능 함수
    void rebirth();
    void death();

    // 캐릭터 정보 출력
    void PrintInfo();

    // Get Info
    std::string GetName();
    int GetHp();
    int GetMp();
    float GetMoveSpeed();
    bool GetAlive();

    // Set Info
    void SetName(std::string _name);
    void SetHp(int _hp);
    void SetMp(int _hp);
    void SetMoveSpeed(float _moveSpeed);
};
