#include <random>
#include "Player.h"
#include "Vayne.h"
#include "SunGlasses.h"

// --------------------------------- CLASS
// --------------------------------- VAYNE

// 공격 함수
void Vayne::RandomAttack(Player* player)
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
bool Vayne::Attack(Player* player)
{
	int dmg;
	int mul = 1;

	setColor(BLUE);
	std::cout << " [ " << this->GetName() << "이(가) "
		<< player->GetName() << "에게 기본 공격! ]" << std::endl;

	dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
		- (player->GetDef() + player->GetDefBuff()));
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool Vayne::SkillA(Player* player)
{
	int dmg;
	int mul = 2;

	setColor(BLUE);
	std::cout << " [ " << this->GetName() << "이(가) "
		<< player->GetName() << "에게 구르기! ]" << std::endl;

	dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
		- (player->GetDef() + player->GetDefBuff()));
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool Vayne::SkillB(Player* player)
{
	int dmg;
	int mul = 3;

	setColor(BLUE);
	std::cout << " [ " << this->GetName() << "이(가) "
		<< player->GetName() << "에게 선고 사용! (스턴: 1턴) ]" << std::endl;

	player->SetStunCnt(player->GetStunCnt() + 1);

	dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
		- (player->GetDef() + player->GetDefBuff()));
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool Vayne::SkillC(Player* player)
{
	int dmg;
	int mul = 1;

	setColor(BLUE);
	std::cout << " [ " << this->GetName()
		<< "이(가) 궁극기 사용! (공격력+3: 3턴) ]" << std::endl;

	this->SetDmgBuffCnt(this->GetDmgBuffCnt() + 3);
	this->SetDmgBuff(this->GetDmgBuff() + 3);

	dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
		- (player->GetDef() + player->GetDefBuff()));
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}

// 기능 함수
void Vayne::DropItem(Player* player)
{
	setColor(SKYBLUE);
	std::cout << " [ 베인의 선글라스를 얻었다! ]" << std::endl;
	std::cout << " [ " << this->GetDropGold() << " 골드를 얻었다! ]" << std::endl;
	std::cout << " [ 인벤토리를 확인해보자! ]" << std::endl;
	player->AddItem(new SunGlasses());
	player->SetGold(player->GetGold() + this->GetDropGold());
}