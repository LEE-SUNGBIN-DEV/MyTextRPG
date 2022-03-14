#include <random>
#include "LUX.h"
#include "Wand.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- LUX
// 공격 함수
void LUX::RandomAttack(Player* player)
{
	int randNum;
	std::random_device rd;

	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 99);

	randNum = dis(gen);

	if (randNum > 90)
	{
		this->SkillC(player);
	}
	else if (randNum > 75 && randNum <= 90)
	{
		this->SkillB(player);
	}
	else if (randNum > 60 && randNum <= 75)
	{
		this->SkillA(player);
	}
	else
	{
		this->Attack(player);
	}
}
bool LUX::Attack(Player* player)
{
	int dmg;
	int mul = 1;

	setColor(BLUE);
	std::cout << "[ " << this->GetName() << "이(가) "
		<< player->GetName() << "에게 기본 공격! ]" << std::endl;

	dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool LUX::SkillA(Player* player)
{
	int dmg;
	int mul = 2;

	setColor(BLUE);
	std::cout << "[ " << this->GetName() << "이(가) "
		<< player->GetName() << "에게 속박 사용! (스턴: 1턴) ]" << std::endl;

	player->SetStunCnt(player->GetStunCnt() + 1);

	dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool LUX::SkillB(Player* player)
{
	int dmg;
	int mul = 1;

	setColor(BLUE);
	std::cout << "[ " << this->GetName() << "이(가) 보호막 사용! (쉴드+5: 2턴) ]" << std::endl;

	this->SetShield(this->GetShield() + 5);
	this->SetShieldCnt(this->GetShieldCnt() + 2);

	dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool LUX::SkillC(Player* player)
{
	int dmg;
	int mul = 6;

	setColor(BLUE);
	std::cout << "[ " << this->GetName() << "이(가) "
		<< player->GetName() << "에게 데마시아!! ]" << std::endl;

	dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}

void LUX::DropItem(Player* player)
{
	setColor(GREEN);
	std::cout << "[ 럭스의 지팡이를 얻었다! ]" << std::endl;
	std::cout << "[ " << this->GetDropGold() << " 골드를 얻었다! ]" << std::endl;
	std::cout << "[ 인벤토리를 확인해보자! ]" << std::endl;
	player->AddItem(new Wand());
	player->SetGold(player->GetGold() + this->GetDropGold());
}
