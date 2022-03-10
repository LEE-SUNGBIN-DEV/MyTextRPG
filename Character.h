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
    Character(std::string _name) : Character()
    {
        this->name = "_name"; 
    }

    ~Character()
    {
    }

    // 기능 함수
    virtual void Rebirth();
    virtual void Death();
    virtual void FreeMemory();

    // 캐릭터 정보 출력
    virtual void PrintInfo();

    // Get Info
    virtual std::string GetName();
    virtual int GetHp();
    virtual int GetMp();
    virtual float GetMoveSpeed();
    virtual bool GetAlive();

    // Set Info
    virtual void SetName(std::string _name);
    virtual void SetHp(int _hp);
    virtual void SetMp(int _hp);
    virtual void SetMoveSpeed(float _moveSpeed);
    virtual void SetAlive(bool _alive);
};
