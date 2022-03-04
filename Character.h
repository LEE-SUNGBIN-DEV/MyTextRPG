#pragma once
#include <iostream>

// --------------------------------- CLASS
// --------------------------------- CHARACTER
class Character
{
private:
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
    Character(std::string _name)
    {
        this->name = "_name";
        this->hp = 100;
        this->mp = 50;
        this->moveSpeed = 1.0f;
        this->alive = true;
    }

    // 기능 함수
    virtual void Rebirth();
    virtual void Death();
    virtual void FreeMemory();

    // 캐릭터 정보 출력
    virtual void PrintInfo();

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
