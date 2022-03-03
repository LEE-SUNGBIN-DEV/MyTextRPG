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
    // ������
    Character()
    {
        this->name = "NONE";
        this->hp = 100;
        this->mp = 50;
        this->moveSpeed = 1.0f;
        this->alive = true;
    }

    // ��� �Լ�
    void rebirth();
    void death();

    // ĳ���� ���� ���
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
