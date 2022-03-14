#include <random>
#include "MasterYi.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- MasterYi
// ���� �Լ�
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

	std::cout << "[ " << this->GetName() << "��(��) "
		<< player->GetName() << "���� �⺻ ����! ]" << std::endl;

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

	std::cout << "[ " << this->GetName() << "��(��) ���ַ� �˼� ���! ]" << std::endl;
	std::cout << "[ ���ݷ� ����(2��) ]" << std::endl;

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

	std::cout << "[ " << this->GetName() << "��(��) ��� ���! ]" << std::endl;
	std::cout << "[ ü�� ȸ�� +50 / ���� ����(2��) ]" << std::endl;

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

	std::cout << "[ ������ �ӵ�! ]" << std::endl;
	std::cout << "[ ���ݷ�/���� ����(3��) ]" << std::endl;

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
	std::cout << "[ ����&��� ������ �����! ]" << std::endl;
	std::cout << "[ ü��/���� ȸ���� +5 ]" << std::endl;
	player->SetHpRecovery(player->GetHpRecovery() + 5);
	player->SetMpRecovery(player->GetMpRecovery() + 5);

	player->SetGold(player->GetGold() + this->GetDropGold());
}