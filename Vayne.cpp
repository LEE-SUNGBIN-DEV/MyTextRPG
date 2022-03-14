#include <random>
#include "Vayne.h"
#include "SunGlasses.h"
#include "Player.h"
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

	std::cout << "[ " << this->GetName() << "��(��) "
		<< player->GetName() << "���� �⺻ ����! ]" << std::endl;

	dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool Vayne::SkillA(Player* player)
{
	int dmg;
	int mul = 2;

	std::cout << "[ " << this->GetName() << "��(��) "
		<< player->GetName() << "���� ������! ]" << std::endl;

	dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool Vayne::SkillB(Player* player)
{
	int dmg;
	int mul = 3;

	std::cout << "[ " << this->GetName() << "��(��) "
		<< player->GetName() << "���� ���� ���! ]" << std::endl;
	std::cout << "[ ����(1��) ]" << std::endl;

	player->SetStunCnt(player->GetStunCnt() + 1);

	dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool Vayne::SkillC(Player* player)
{
	int dmg;
	int mul = 1;

	std::cout << "[ " << this->GetName() << "��(��) �ñر� ���!" << std::endl;
	std::cout << "[ 3�ϵ��� ������ ���ݷ��� 3���� �մϴ� ]" << std::endl;

	this->SetDmgBuffCnt(this->GetDmgBuffCnt() + 3);
	this->SetDmgBuff(this->GetDmgBuff() + 3);

	dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}

// ��� �Լ�
void Vayne::DropItem(Player* player)
{
	std::cout << "[ ������ ���۶󽺸� �����! ]" << std::endl;
	player->AddItem(new SunGlasses());
	player->SetGold(player->GetGold() + this->GetDropGold());
}