#include "Equipment.h"
#include "Player.h"

// ���
void Equipment::PrintItem()
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "[" << this->GetItemName() << "] "
		<< "[" << this->GetItemNum() << "] ";
	if (this->GetIsEquip())
	{
		std::cout << "[ ������ ]" << std::endl;
	}
	else
	{
		std::cout << "[ �������� ]" << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
}
void Equipment::PrintItem(int _index)
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "[���� ��ȣ: " << _index << "] "
		<< "[" << this->GetItemName() << "] "
		<< "[" << this->GetItemNum() << "] ";
	if (this->GetIsEquip())
	{
		std::cout << "[ ������ ]" << std::endl;
	}
	else
	{
		std::cout << "[ �������� ]" << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
}

// ��� �Լ�
void Equipment::UseItem(Player* player)
{
	// ������
	if (this->GetIsEquip())
	{
		this->SetIsEquip(false);
		player->SetDmg(player->GetDmg() - this->GetDmg());
		player->SetDef(player->GetDef() - this->GetDef());
		player->SetMaxHp(player->GetMaxHp() - this->GetHp());
		player->SetHp(player->GetHp() - this->GetHp());
		player->SetMaxMp(player->GetMaxMp() - this->GetMp());
		player->SetMp(player->GetMp() - this->GetMp());
		std::cout << "[ " << this->GetItemName() << "�������� ���� �����Ͽ����ϴ�. ]" << std::endl;
	}

	// ������
	else
	{
		this->SetIsEquip(true);
		player->SetDmg(player->GetDmg() + this->GetDmg());
		player->SetDef(player->GetDef() + this->GetDef());
		player->SetMaxHp(player->GetMaxHp() + this->GetHp());
		player->SetHp(player->GetHp() + this->GetHp());
		player->SetMaxMp(player->GetMaxMp() + this->GetMp());
		player->SetMp(player->GetMp() + this->GetMp());
		std::cout << "[ " << this->GetItemName() << "�������� �����Ͽ����ϴ�. ]" << std::endl;
	}
}

// get
bool Equipment::GetIsEquip() { return this->isEquip; }
int Equipment::GetDmg() { return this->dmg; }
int Equipment::GetDef() { return this->def; }
int Equipment::GetHp() { return this->hp; }
int Equipment::GetMp() { return this->mp; }

// set
void Equipment::SetIsEquip(bool _isEquip)
{
	this->isEquip = _isEquip;
	return;
}
void Equipment::SetDmg(int _dmg)
{
	this->dmg = _dmg;
	return;
}
void Equipment::SetDef(int _def)
{
	this->def = _def;
	return;
}
void Equipment::SetHp(int _hp)
{
	this->hp = _hp;
	return;
}
void Equipment::SetMp(int _mp)
{
	this->mp = _mp;
	return;
}