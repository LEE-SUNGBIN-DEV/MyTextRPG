#include <random>
#include "Player.h"
#include "Vayne.h"
#include "SunGlasses.h"

// --------------------------------- CLASS
// --------------------------------- VAYNE

// ���� �Լ�
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
	std::cout << " [ " << this->GetName() << "��(��) "
		<< player->GetName() << "���� �⺻ ����! ]" << std::endl;

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
	std::cout << " [ " << this->GetName() << "��(��) "
		<< player->GetName() << "���� ������! ]" << std::endl;

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
	std::cout << " [ " << this->GetName() << "��(��) "
		<< player->GetName() << "���� ���� ���! (����: 1��) ]" << std::endl;

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
		<< "��(��) �ñر� ���! (���ݷ�+3: 3��) ]" << std::endl;

	this->SetDmgBuffCnt(this->GetDmgBuffCnt() + 3);
	this->SetDmgBuff(this->GetDmgBuff() + 3);

	dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
		- (player->GetDef() + player->GetDefBuff()));
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}

// ��� �Լ�
void Vayne::DropItem(Player* player)
{
	setColor(SKYBLUE);
	std::cout << " [ ������ ���۶󽺸� �����! ]" << std::endl;
	std::cout << " [ " << this->GetDropGold() << " ��带 �����! ]" << std::endl;
	std::cout << " [ �κ��丮�� Ȯ���غ���! ]" << std::endl;
	player->AddItem(new SunGlasses());
	player->SetGold(player->GetGold() + this->GetDropGold());
}