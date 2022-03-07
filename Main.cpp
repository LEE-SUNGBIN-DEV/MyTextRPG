#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Character.h"
#include "Monster.h"
#include "Player.h"

using namespace std;

string gameTitle = "TEXT RPG";

// init
int MainTitle()
{
    int titleSel;

    system("cls");
    cout << "==========================" << endl;
    cout << "��" << gameTitle << endl;
    cout << "==========================" << endl;
    cout << "1. ���� ����" << endl;
    cout << "2. ���� ����" << endl;
    cout << "���� >> ";

    cin >> titleSel;

    return titleSel;
}
void CreatePlayer(vector<Player*>& playerList, Player*& player)
{
    int typeSel;

    system("cls");
    cout << "==========================" << endl;
    cout << "������ �����ϼ���." << endl;
    cout << "1. ����" << endl;
    cout << "2. ������" << endl;
    cout << "==========================" << endl;
    
    while (true)
    {
        cout << "���� >> ";
        cin >> typeSel;

        if (typeSel == ENUM_PLAYER_KNIGHT
            || typeSel == ENUM_PLAYER_MAGICIAN)
        {
            player = new Player(typeSel);
            playerList.push_back(player);

            return;
        }

        else
        {
            cout << "ERROR: WRONG INPUT: SetPlayer()" << endl;
        }
    }
}
void SetUserInfo(vector<Player*>& playerList, int playerIndex)
{
    string playerStrInput;
    int playerIntInput;

    system("cls");
    cout << "==========================" << endl;
    cout << "������ �Է��ϼ���." << endl;
    cout << "==========================" << endl;

    cout << "�Է� >> ";
    cin >> playerStrInput;
    
    system("cls");
    cout << "==========================" << endl;
    cout << "���̸� �Է��ϼ���." << endl;
    cout << "==========================" << endl;

    cout << "�Է� >> ";
    cin >> playerIntInput;

    playerList[playerIndex]->SetUserInfo(playerStrInput, playerIntInput);

    system("cls");
    playerList[playerIndex]->PrintUserInfo();

    cin.get();
    cin.get();

    return;
}
void SetCharInfo(vector<Player*>& playerList, int playerIndex)
{
    string playerStrInput;

    system("cls");
    cout << "==========================" << endl;
    cout << "�г����� �Է��ϼ���." << endl;
    cout << "==========================" << endl;

    cout << "�Է� >> ";
    cin >> playerStrInput;
    playerList[playerIndex]->SetName(playerStrInput);

    system("cls");
    cout << "==========================" << endl;
    cout << "ĳ���� ���� �Ϸ�" << endl;
    cout << "==========================" << endl;
    playerList[playerIndex]->PrintInfo();

    cin.get();
    cin.get();

    return;
}
void CreateMonster(vector<Monster*>& monsterList, Monster*& monster)
{
    string monSel;

    while (true)
    {
        cout << "----------------------------------------------------" << endl;
        cout << "(���� ����) ���: ������, ���, �巡�� / X: ����" << endl;
        cout << "----------------------------------------------------" << endl;
        cin >> monSel;
        if (monSel == "������" || monSel == "���" || monSel == "�巡��")
        {
            monster = new Monster(monSel);
            monsterList.push_back(monster);
            cout << monSel << " " << "���� �Ϸ�" << endl;
        }

        else if (monSel == "X")
        {
            return;
        }

        else
        {
            cout << "ERROR: UNKNOWN MONSTER TYPE" << endl;
        }
    }
}

// Combat Menu
void CombatMenu(Player* player, Monster* monster)
{
    int combatSel = 0;

    system("cls");
    cout << "==========================" << endl;
    cout << " ���� �޴�" << endl;
    cout << "==========================" << endl;
    cout << " 1. �Ϲ� ����" << endl;
    cout << " 2. ��ų 1" << endl;
    cout << " 3. ��ų 2" << endl;
    cout << " 4. ��ų 3" << endl;
    cout << " 0. ������" << endl;
    cout << "==========================" << endl;

    while (true)
    {
        cout << "�Է� >> ";
        cin >> combatSel;
        switch (combatSel)
        {
        case 1:
            player->Attack(monster);
            break;
        case 2:
            player->SkillA(monster);
            break;
        case 3:
            player->SkillB(monster);
            break;
        case 4:
            player->SkillC(monster);
            break;
        case 0: return;
        }

        if (monster->GetHp() <= 0)
        {
            monster->Death();
            cout << "���� ����" << endl;
            return;
        }
        cout << monster->GetName() << " HP : " << monster->GetHp() << endl;

        monster->Attack(player);
        if (player->GetHp() <= 0)
        {
            player->Death();
            cout << "���� ����" << endl;
            return;
        }
        cout << player->GetName() << " HP : " << player->GetHp() << endl;
    }
}

// Scene
void Chapter1(Player* player, int* _progress)
{ 
    Monster* monster = NULL;

    while (*_progress == 1)
    {
        monster = new Monster("������");
        system("cls");
        std::cout << "==========================" << std::endl;
        std::cout << "Chapter " << *_progress << std::endl;
        std::cout << "[������ ���]" << std::endl;
        std::cout << "==========================" << std::endl;

        cin.get();
        CombatMenu(player, monster);

        if (monster->GetAlive() == false
            && player->GetAlive() == true)
        {
            std::cout << "==========================" << std::endl;
            std::cout << "Chapter " << *_progress << std::endl;
            std::cout << "[������ ���] Ŭ����" << std::endl;
            std::cout << "==========================" << std::endl;
            delete(monster);
            *_progress = *_progress + 1;
            cin.get();
            return;
        }

        else
        {
            cout << "Game Over" << endl;
            delete(monster);
            cin.get();
            return;
        }
    }

    if (*_progress != 1)
    {
        std::cout << "ERROR: WRONG ACCESS: MAIN STREAM CHAPTER " << *_progress << std::endl;
        return;
    }

    return;
}
void Chapter2(Player* player, int* _progress)
{
}
//
int FindNicknameIndex(vector<Player*> player, string nick);
void PrintSearchPlayer(vector<Player*> player, int index);

// --------------------------------- Main
int main()
{
    Player* player = NULL;
    Monster* monster = NULL;
    vector<Player*> playerList;
    vector<Monster*> monsterList;
    int* progress = new int(1);
    int sel = 0;

    sel = MainTitle();

    switch (sel)
    {
    case 1:
        CreatePlayer(playerList, player);
        SetUserInfo(playerList, 0);
        SetCharInfo(playerList, 0);

        Chapter1(playerList[0], progress);
        Chapter2(playerList[0], progress);

    case 2:
        return 0;
    }
    
    //

    return 0;
}

// �г��� Ž���ؼ� ��ġ�ϴ� �г��� ����� �ش� "�ε���" ��ȯ
int FindNicknameIndex(vector<Player*> playerList, string nick)
{
    cout << "-------------------------------------" << endl;
    cout << "�г���: " << nick << "��(��) Ž���մϴ�." << endl;

    for (int i = 0; i < playerList.size(); i++)
    {
        if (nick == playerList[i]->GetName())
        {
            cout << "��ġ�ϴ� �÷��̾ �����մϴ�." << endl;
            cout << "IndexNum: " << i << endl;
            cout << "-------------------------------------" << endl;

            return i;
        }
    }
    cout << "��ġ�ϴ� �÷��̾ �������� �ʽ��ϴ�." << endl;
    cout << "-------------------------------------" << endl;

    return -1;
}

// �г��� Ž���ؼ� ��ġ�ϴ� �г��� ����� �÷��̾� ���� "���"
void PrintSearchPlayer(vector<Player*> playerList, int index)
{
    if (index == -1)
        return;

    else
    {
        cout << "�ش� �÷��̾��� ����" << endl;
        playerList[index]->PrintInfo();
    }
}