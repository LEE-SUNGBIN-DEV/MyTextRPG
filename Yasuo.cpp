#include "Yasuo.h"
#include "Player.h"
// --------------------------------- CLASS
// --------------------------------- YASUO
// 공격 함수
void Yasuo::RandomAttack(Player* player)
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
bool Yasuo::Attack(Player* player)
{
	int dmg;

	dmg = this->GetDmg() - player->GetDef();

	if (dmg < 0) dmg = 0;

	std::cout << "[ " << this->GetName() << "이(가) "
		<< player->GetName() << "에게 기본 공격! ]" << std::endl;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool Yasuo::SkillA(Player* player)
{
	int dmg;
	int mul = 2;

	dmg = mul * this->GetDmg() - player->GetDef();

	if (dmg < 0) dmg = 0;

	std::cout << "[ " << this->GetName() << "이(가) "
		<< player->GetName() << "에게 속박 사용! ]" << std::endl;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool Yasuo::SkillB(Player* player)
{
	this->SetShield(this->GetShield() + 7);
	this->SetShieldCnt(this->GetShieldCnt() + 2);

	std::cout << "[ " << this->GetName() << "이(가) 보호막 사용! ]" << std::endl;

	this->TurnManager();

	return true;
}
bool Yasuo::SkillC(Player* player)
{
	int dmg;
	int mul = 6;

	dmg = mul * this->GetDmg() - player->GetDef();

	if (dmg < 0) dmg = 0;

	std::cout << "[ " << this->GetName() << "이(가) "
		<< player->GetName() << "에게 데마시아!! ]" << std::endl;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
