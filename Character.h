#pragma once
#include <iostream>

// --------------------------------- CLASS
// --------------------------------- CHARACTER
class Character
{
private:
    std::string name;
    int maxHp;
    int maxMp;
    int hp;
    int mp;
    int dmg;
    int def;
    int shield;
    int shieldTurn;
    bool alive;

public:
    // 생성자
    Character()
    {
        this->SetName("NONE");
        this->SetMaxHp(100);
        this->SetMaxMp(50);
        this->SetHp(100);
        this->SetMp(50);
        this->SetDmg(1);
        this->SetDef(0);
        this->SetShield(0);
        this->SetShieldCnt(0);
        this->SetAlive(true);
    }
    Character(std::string _name) : Character()
    {
        this->SetName(_name); 
    }

    // 기능 함수
    virtual void Rebirth();
    virtual void Death();
    virtual void FreeMemory();

    // 관리 함수
    virtual void TurnManager();
    virtual void HpShieldManager(int _dmg);

    // 캐릭터 정보 출력
    virtual void PrintInfo();

    // Get Info
    virtual std::string GetName();
    virtual int GetMaxHp();
    virtual int GetMaxMp();
    virtual int GetHp();
    virtual int GetMp();
    virtual int GetDmg();
    virtual int GetDef();
    virtual int GetShield();
    virtual int GetShieldCnt();
    virtual bool GetAlive();
    

    // Set Info
    virtual void SetName(std::string _name);
    virtual void SetMaxHp(int _maxHp);
    virtual void SetMaxMp(int _maxMp);
    virtual void SetHp(int _hp);
    virtual void SetMp(int _hp);
    virtual void SetDmg(int _dmg);
    virtual void SetDef(int _def);
    virtual void SetShield(int _shield);
    virtual void SetShieldCnt(int _cnt);
    virtual void SetAlive(bool _alive);
    
};
