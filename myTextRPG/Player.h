#pragma once
#include <vector>
#include "Item.h"
#include "Character.h"

class Monster;

// 직업 목록
enum MyPlayerType
{
    ENUM_PLAYER_NONE,
    ENUM_PLAYER_KNIGHT,
    ENUM_PLAYER_WIZARD
};

struct UserInfo
{
    std::string userName;
    int userAge;

    UserInfo()
    {
        this->userName = "NONE";
        this->userAge = 0;
    }
};

// --------------------------------- CLASS
// --------------------------------- PLAYER
class Player : public Character
{
private:
    UserInfo userInfo;
    std::vector<Item*> userInventory;
    std::string SkillNameA;
    std::string SkillNameB;
    std::string SkillNameC;
    std::string typeName;
    int playerType;
    int exp;
    int gold;

public:
    // 생성자
    Player()
    {
        this->SetPlayerType(ENUM_PLAYER_NONE);
        this->SetExp(0);
        this->SetGold(50);
        this->SetSkillNameA("NONE_A");
        this->SetSkillNameB("NONE_B");
        this->SetSkillNameC("NONE_C");
    }

    // 공격 함수
    virtual bool Attack(Monster* monster);
    virtual bool SkillA(Monster* monster);
    virtual bool SkillB(Monster* monster);
    virtual bool SkillC(Monster* monster);

    // 기능 함수
    void PrintInfo();
    void PrintUserInfo();
    void PrintInventory();
    void PrintInventoryEquipment();

    void AddItem(std::string _itemName);
    void AddItem(std::string _itemName, int _itemNum);
    void AddItem(Item* _item);
    void RemoveItem(int _index);
    void RemoveItem(std::string _name);
    void RemoveItem(std::string _name, int _itemNum);
    int SearchItem(std::string _name);
    void UseInventoryItem(int _index);

    // Get Info
    std::vector<Item*> GetInventory();
    std::string GetItemName(int _index);
    std::string GetOriginName(int _index);
    int GetItemHoningLevel(int _index);
    int GetItemDmg(int _index);
    int GetItemDef(int _index);
    int GetItemHp(int _index);
    int GetItemMp(int _index);
    bool GetIsEquip(int _index);
    std::string GetUserName();
    std::string GetTypeName();
    UserInfo GetUserInfo();
    int GetUserAge();
    int GetExp();
    int GetItemNum(int i);
    int GetPlayerType();
    int GetGold();
    std::string GetSkillNameA();
    std::string GetSkillNameB();
    std::string GetSkillNameC();

    // Set Info
    void SetItemName(std::string _itemName, int _index);
    void SetOriginName(std::string _originName, int _index);
    void SetItemHoningLevel(int _honingLevel, int _index);
    void SetItemDmg(int _dmg, int _index);
    void SetItemDef(int _def, int _index);
    void SetItemHp(int _hp, int _index);
    void SetItemMp(int _mp, int _index);
    void SetIsEquip(bool _isEquip, int _index);
    void SetUserInfo(std::string _name, int _age);
    void SetExp(int _exp);
    void SetPlayerType(int _sel);
    void SetGold(int _money);
    void SetTypeName(std::string _typeName);
    void SetSkillNameA(std::string _skillName);
    void SetSkillNameB(std::string _skillName);
    void SetSkillNameC(std::string _skillName);
};