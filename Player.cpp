#include "Player.h"
#include "Monster.h"
#include "Item.h"

// --------------------------------- CLASS
// --------------------------------- PLAYER

// ----------------------공격 함수
bool Player::Attack(Monster* monster)
{
    int dmg;
    int mul = 1;

    setColor(RED);
    std::cout << "[ " << this->GetName() << "이(가) "
        << monster->GetName() << "에게 기본 공격! ]" << std::endl;

    dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
    if (dmg < 0) dmg = 0;

    monster->HpShieldManager(dmg);
    this->TurnManager();

    return true;
}
bool Player::SkillA(Monster* monster)
{
    int dmg;
    int mul = 2;
    int needMana = 20;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << "[ 마나가 부족합니다. ]" << std::endl;
        return false;
    }
    else
    {
        std::cout << "[ " << this->GetName() << "이(가) "
            << monster->GetName() << "에게 스킬A 사용! ]" << std::endl;

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
        if (dmg < 0) dmg = 0;

        this->SetMp(this->GetMp() - needMana);
        monster->HpShieldManager(dmg);
        this->TurnManager();

        return true;
    }
    
}
bool Player::SkillB(Monster* monster)
{
    int dmg;
    int mul = 3;
    int needMana = 30;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << "[ 마나가 부족합니다. ]" << std::endl;
        return false;
    }

    else
    {
        std::cout << "[ " << this->GetName() << "이(가) "
            << monster->GetName() << "에게 스킬B 사용! ]" << std::endl;

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
        if (dmg < 0) dmg = 0;

        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}
bool Player::SkillC(Monster* monster)
{
    int dmg;
    int mul = 4;
    int needMana = 50;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << "[ 마나가 부족합니다. ]" << std::endl;
        return false;
    }

    else
    {
        std::cout << "[ " << this->GetName() << "이(가) "
            << monster->GetName() << "에게 스킬C 사용!] " << std::endl;

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
        if (dmg < 0) dmg = 0;

        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}

// ----------------------기능 함수
// 정보 출력
void Player::PrintInfo()
{
    Character::PrintInfo();
    std::cout << "[ 직업: " << this->GetTypeName() << " ]" << std::endl;
    std::cout << "[ 소지금: " << this->GetGold() << " ]" << std::endl;
    std::cout << "[ 경험치: " << this->GetExp() << " ]" << std::endl;

    return;
}
void Player::PrintUserInfo()
{
    setColor(YELLOW);
    std::cout << "==========================" << std::endl;
    std::cout << "성함 : " << this->GetUserName() << std::endl;
    std::cout << "나이 : " << this->GetUserAge() << std::endl;
    std::cout << "==========================" << std::endl;
}
void Player::PrintInventory()
{
    if (this->userInventory.size() == 0)
    {
        setColor(GREEN);
        std::cout << "[ 인벤토리가 비었습니다. ]" << std::endl;
    }
    for (int i = 0; i < this->userInventory.size(); i++)
    {
        this->userInventory[i]->PrintItem(i);
    }
}

// 아이템 추가
void Player::AddItem(std::string _itemName)
{
    for (int i = 0; i < userInventory.size(); i++)
    {
        // 인벤에 같은 아이템이 존재할 경우
        if (userInventory[i]->GetItemName() == _itemName)
        {
            // 수량만 추가
            userInventory[i]->SetItemNum(userInventory[i]->GetItemNum() + 1);
            return;
        }
    }

    // 존재하지 않을 경우 새로 추가
    this->userInventory.push_back(new Item(_itemName, 1));
    return;
}
void Player::AddItem(std::string _itemName, int _itemNum)
{
    for (int i = 0; i < userInventory.size(); i++)
    {
        // 인벤에 같은 아이템이 존재할 경우
        if (userInventory[i]->GetItemName() == _itemName)
        {
            // 수량만 추가
            userInventory[i]->SetItemNum(userInventory[i]->GetItemNum() + _itemNum);
            return;
        }
    }

    // 존재하지 않을 경우 새로 추가
    this->userInventory.push_back(new Item(_itemName, _itemNum));
    return;
}
void Player::AddItem(Item* _item)
{
    for (int i = 0; i < userInventory.size(); i++)
    {
        // 인벤에 같은 아이템이 존재할 경우
        if (userInventory[i]->GetItemName() == _item->GetItemName())
        {
            // 수량만 추가
            userInventory[i]->SetItemNum(userInventory[i]->GetItemNum() + 1);
            delete(_item);

            return;
        }
    }
    this->userInventory.push_back(_item);
    return;
}

// 아이템 삭제
void Player::RemoveItem(int _index) // 인덱스로 삭제
{
    // 1개 이상일 경우
    if (userInventory[_index]->GetItemNum() > 1)
    {
        userInventory[_index]->SetItemNum(userInventory[_index]->GetItemNum() - 1);
        return;
    }

    // 1개 일 경우
    else
    {
        userInventory.erase(userInventory.begin() + _index);
    }

    return;
}
void Player::RemoveItem(std::string _name)
{
    for (int i = 0; i < userInventory.size(); i++)
    {
        // 존재할 경우
        if (userInventory[i]->GetItemName() == _name)
        {
            // 1개 이상일 경우
            if (userInventory[i]->GetItemNum() > 1)
            {
                userInventory[i]->SetItemNum(userInventory[i]->GetItemNum() - 1);
                return;
            }

            // 1개 일 경우
            else
            {
                userInventory.erase(userInventory.begin() + i);
            }
        }
    }

    return;
}
void Player::RemoveItem(std::string _name, int _itemNum)
{
    for (int i = 0; i < userInventory.size(); i++)
    {
        // 존재할 경우
        if (userInventory[i]->GetItemName() == _name)
        {
            // 보유 수량이 버리려는 수량보다 적으면
            if (userInventory[i]->GetItemNum() <= _itemNum)
            {
                // 전부 버리기
                userInventory.erase(userInventory.begin() + i);
                return;
            }

            else
            {
                userInventory[i]->SetItemNum(userInventory[i]->GetItemNum() - _itemNum);
                return;
            }
            
        }
    }

    return;
}

int Player::SearchItem(std::string _name)
{
    for (int i = 0; i < this->userInventory.size(); i++)
    {
        if (this->userInventory[i]->GetItemName() == _name)
        {
            return i;
        }
    }

    return -1;
}
void Player::UseInventoryItem(int _index)
{
    if (this->userInventory[_index]->GetItemNum() > 0)
    {
        this->userInventory[_index]->UseItem(this);
        if (this->userInventory[_index]->GetItemType() != ENUM_ITEM_EQUIP)
        {
            this->RemoveItem(_index);
        }
    }
}

// Get
UserInfo Player::GetUserInfo() { return this->userInfo; }
std::vector<Item*> Player::GetInventory() { return this->userInventory; }
std::string Player::GetItemName(int i) { return this->userInventory[i]->GetItemName(); }
std::string Player::GetTypeName() { return this->typeName; }
std::string Player::GetUserName() { return this->userInfo.userName; }
int Player::GetExp() { return this->exp; }
int Player::GetUserAge() { return this->userInfo.userAge; }
int Player::GetItemNum(int i) { return this->userInventory[i]->GetItemNum(); }
int Player::GetPlayerType() { return this->playerType; }
int Player::GetGold() { return this->gold; }
std::string Player::GetSkillNameA() { return this->SkillNameA; }
std::string Player::GetSkillNameB() { return this->SkillNameB; }
std::string Player::GetSkillNameC() { return this->SkillNameC; }

// Set Info
void Player::SetUserInfo(std::string _name, int _age)
{
    this->userInfo.userName = _name;
    this->userInfo.userAge = _age;
}
void Player::SetExp(int _exp)
{
    this->exp = _exp;
    return;
}
void Player::SetPlayerType(int _sel)
{
    this->playerType = _sel;
    return;
}
void Player::SetGold(int _money)
{
    this->gold = _money;
    return;
}
void Player::SetTypeName(std::string _typeName)
{
    this->typeName = _typeName;
    return;
}
void Player::SetSkillNameA(std::string _skillName)
{
    this->SkillNameA = _skillName;
    return;
}
void Player::SetSkillNameB(std::string _skillName)
{
    this->SkillNameB = _skillName;
    return;
}
void Player::SetSkillNameC(std::string _skillName)
{
    this->SkillNameC = _skillName;
    return;
}