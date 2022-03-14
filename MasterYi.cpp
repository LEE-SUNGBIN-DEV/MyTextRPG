#include <random>
#include "MasterYi.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- MasterYi
// 공격 함수
void MasterYi::RandomAttack(Player* player)
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
bool MasterYi::Attack(Player* player)
{
	int dmg;
	int mul = 1;

	std::cout << "[ " << this->GetName() << "이(가) "
		<< player->GetName() << "에게 기본 공격! ]" << std::endl;

	dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool MasterYi::SkillA(Player* player)
{
	int dmg;
	int mul = 1;

	std::cout << "[ " << this->GetName() << "이(가) 우주류 검술 사용! ]" << std::endl;
	std::cout << "[ 공격력 증가(2턴) ]" << std::endl;

	this->SetDmgBuff(this->GetDmgBuff() + 10);
	this->SetDmgBuffCnt(this->GetDmgBuffCnt() + 2);

	dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool MasterYi::SkillB(Player* player)
{
	int dmg;
	int mul = 1;

	this->SetShield(this->GetShield() + 100);
	this->SetShieldCnt(this->GetShieldCnt() + 2);

	std::cout << "[ " << this->GetName() << "이(가) 명상 사용! ]" << std::endl;
	std::cout << "[ 체력 회복 +50 / 방어력 증가(2턴) ]" << std::endl;

	this->SetHp(this->GetHp() + 50);
	this->SetDefBuff(this->GetDefBuff() + 5);
	this->SetDefBuffCnt(this->GetDefBuffCnt() + 2);

	dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool MasterYi::SkillC(Player* player)
{
	int dmg;
	int mul = 6;

	std::cout << "[ 생각의 속도! ]" << std::endl;
	std::cout << "[ 공격력/방어력 증가(3턴) ]" << std::endl;

	this->SetDmgBuff(this->GetDmgBuff() + 5);
	this->SetDmgBuffCnt(this->GetDmgBuffCnt() + 3);
	this->SetDefBuff(this->GetDefBuff() + 5);
	this->SetDefBuffCnt(this->GetDefBuffCnt() + 3);

	dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}

void MasterYi::DropItem(Player* player)
{
	std::cout << "[ 레드&블루 버프를 얻었다! ]" << std::endl;
	std::cout << "[ 체력/마나 회복력 +5 ]" << std::endl;
	player->SetHpRecovery(player->GetHpRecovery() + 5);
	player->SetMpRecovery(player->GetMpRecovery() + 5);

	player->SetGold(player->GetGold() + this->GetDropGold());
}