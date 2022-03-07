#pragma once
#include <iostream>

// --------------------------------- CLASS
// --------------------------------- CHARACTER
class Character
{
protected:
    std::string name;
    int hp;
    int mp;
    float moveSpeed;
    bool alive;

public:
    // ������
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

    // ��� �Լ�
    virtual void Rebirth();
    virtual void Death();
    virtual void FreeMemory();

    // ĳ���� ���� ���
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
};
