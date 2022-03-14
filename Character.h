#pragma once
#include <iostream>
#include <windows.h>

enum COLOR {
    BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VOILET,
    DAKR_YELLOW,
    GRAY,
    DARK_GRAY,
    BLUE,
    GREEN,
    SKYBLUE,
    RED,
    VIOLET,
    YELLOW,
    WHITE,
};
void setColor(unsigned short text);

// --------------------------------- CLASS
// --------------------------------- CHARACTER
class Character
{
private:
    std::string name;
    std::string title;
    int maxHp;
    int maxMp;
    int hp;
    int hpRecovery;
    int mp;
    int mpRecovery;
    int dmg;
    int def;
    int shield;
    int shieldCnt;
    int stunCnt;
    int dmgBuff;
    int dmgBuffCnt;
    int defBuff;
    int defBuffCnt;
    bool alive;

public:
    // 생성자
    Character()
    {
        this->SetTitle("");
        this->SetName("NONE");
        this->SetMaxHp(100);
        this->SetMaxMp(50);
        this->SetHp(100);
        this->SetMp(50);
        this->SetHpRecovery(0);
        this->SetMpRecovery(5);
        this->SetDmg(1);
        this->SetDef(0);
        this->SetShield(0);
        this->SetShieldCnt(0);
        this->SetStunCnt(0);
        this->SetDmgBuff(0);
        this->SetDmgBuffCnt(0);
        this->SetDefBuff(0);
        this->SetDefBuffCnt(0);
        this->SetAlive(true);
    }
    Character(std::string _name) : Character()
    {
        this->SetName(_name); 
    }

    // 기능 함수
    virtual void Rebirth();
    virtual void Death();
    virtual void InitHp();
    virtual void InitMp();

    // 관리 함수
    virtual void TurnManager();
    virtual void HpShieldManager(int _dmg);

    // 캐릭터 정보 출력
    virtual void PrintInfo();

    // Get Info
    virtual std::string GetName();
    virtual std::string GetTitle();
    virtual int GetMaxHp();
    virtual int GetMaxMp();
    virtual int GetHp();
    virtual int GetHpRecovery();
    virtual int GetMp();
    virtual int GetMpRecovery();
    virtual int GetDmg();
    virtual int GetDef();
    virtual int GetShield();
    virtual int GetShieldCnt();
    virtual int GetStunCnt();
    virtual int GetDmgBuff();
    virtual int GetDmgBuffCnt();
    virtual int GetDefBuff();
    virtual int GetDefBuffCnt();
    virtual bool GetAlive();
    

    // Set Info
    virtual void SetName(std::string _name);
    virtual void SetTitle(std::string _name);
    virtual void SetMaxHp(int _maxHp);
    virtual void SetMaxMp(int _maxMp);
    virtual void SetHp(int _hp);
    virtual void SetHpRecovery(int _hpRecovery);
    virtual void SetMp(int _hp);
    virtual void SetMpRecovery(int _mpRecovery);
    virtual void SetDmg(int _dmg);
    virtual void SetDef(int _def);
    virtual void SetShield(int _shield);
    virtual void SetShieldCnt(int _shieldCnt);
    virtual void SetStunCnt(int _stunCnt);
    virtual void SetDmgBuff(int _dmgBuff);
    virtual void SetDmgBuffCnt(int _dmgBuffCnt);
    virtual void SetDefBuff(int _defBuff);
    virtual void SetDefBuffCnt(int _defBuffCnt);
    virtual void SetAlive(bool _alive);
    
};
