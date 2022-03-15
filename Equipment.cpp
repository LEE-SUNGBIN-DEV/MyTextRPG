#include "Equipment.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- EQUIPMENT
// ���
void Equipment::PrintItem()
{
	setColor(SKYBLUE);
	std::cout << "--------------------------------" << std::endl;
	std::cout << " [" << this->GetItemName() << "] "
		<< "[ ����: " << this->GetItemNum() << "] ";
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
	setColor(SKYBLUE);
	std::cout << "--------------------------------" << std::endl;
	std::cout << " [ ���� ��ȣ: " << _index << "] "
		<< "[" << this->GetItemName() << "] "
		<< "[ ����: " << this->GetItemNum() << "] ";
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
	setColor(SKYBLUE);
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
		std::cout << " [ " << this->GetItemName() << "�������� ���� �����Ͽ����ϴ�. ]" << std::endl;
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
		std::cout << " [ " << this->GetItemName() << "�������� �����Ͽ����ϴ�. ]" << std::endl;
	}
}
