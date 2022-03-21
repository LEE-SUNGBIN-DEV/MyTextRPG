#include <random>
#include "Player.h"
#include "Yasuo.h"
#include "TitleScientist.h"

// --------------------------------- CLASS
// --------------------------------- YASUO

// ���� �Լ�
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
	int mul = 1;

	setColor(BLUE);
	std::cout << " [ " << this->GetName() << "��(��) "
		<< player->GetName() << "���� �⺻ ����! ]" << std::endl;

	dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
		- (player->GetDef() + player->GetDefBuff()));
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool Yasuo::SkillA(Player* player)
{
	int dmg;
	int mul = 2;

	setColor(BLUE);
	std::cout << " [ " << this->GetName() << "��(��) "
		<< player->GetName() << "���� ��ö ��ǳ ���! ]" << std::endl;

	dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
		- (player->GetDef() + player->GetDefBuff()));
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool Yasuo::SkillB(Player* player)
{
	int dmg;
	int mul = 1;

	setColor(BLUE);
	std::cout << " [ " << this->GetName()
		<< "��(��) �ٶ��帷 ���! (����+50: 2��) ]" << std::endl;

	this->SetShield(this->GetShield() + 50);
	this->SetShieldCnt(this->GetShieldCnt() + 2);

	dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
		- (player->GetDef() + player->GetDefBuff()));
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool Yasuo::SkillC(Player* player)
{
	int dmg;
	int mul = 6;

	setColor(BLUE);
	std::cout << " [ " << this->GetName() << "��(��) "
		<< player->GetName() << "���� �츮���Ե�!!! ]" << std::endl;

	dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
		- (player->GetDef() + player->GetDefBuff()));
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}

// ��� �Լ�
void Yasuo::DropItem(Player* player)
{
	setColor(SKYBLUE);
	std::cout << " [ Īȣ: �����ڸ� �����! ]" << std::endl;
	std::cout << " [ " << this->GetDropGold() << " ��带 �����! ]" << std::endl;
	std::cout << " [ �κ��丮�� Ȯ���غ���! ]" << std::endl;
	player->AddItem(new TitleScientist());
	player->SetGold(player->GetGold() + this->GetDropGold());
}