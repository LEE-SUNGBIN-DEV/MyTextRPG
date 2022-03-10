#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Character.h"
#include "Monster.h"
#include "Player.h"
#include "Shop.h"

using namespace std;

string gameTitle = "TEXT RPG";

// global
Shop* shop = new Shop();

// init
int MainTitle()
{
    int userSel;
    
    while (true)
    {
        std::system("cls");
        cout << "==========================" << endl;
        cout << "��[" << gameTitle << " ]" << endl;
        cout << "==========================" << endl;
        cout << "[ 1. ���� ���� ]" << endl;
        cout << "[ 2. ���� ���� ]" << endl;
        cout << "���� >> ";

        cin >> userSel;

        try
        {
            if (userSel == 1 || userSel == 2)
            {
                return userSel;
            }
        }
        catch (char ch)
        {
            cout << "ERROR: WRONG INPUT: MainTitle() " << ch << endl;
            cout << "[ Ȯ��: Enter ]" << endl;
            cin.get();
            cin.get();
        }
    }
}
void CreatePlayer(vector<Player*>& playerList, Player*& player)
{
    int userSel;

    while (true)
    {
        std::system("cls");
        cout << "==========================" << endl;
        cout << "[ ������ �����ϼ���. ]" << endl;
        cout << "[ 1. ���� ]" << endl;
        cout << "[ 2. ������ ]" << endl;
        cout << "==========================" << endl;
        cout << "���� >> ";

        cin >> userSel;

        if (userSel == ENUM_PLAYER_KNIGHT
            || userSel == ENUM_PLAYER_MAGICIAN)
        {
            player = new Player(userSel);
            playerList.push_back(player);

            return;
        }

        else
        {
            cout << "ERROR: WRONG INPUT: CreatePlayer()" << endl;
            cout << "[ Ȯ��: Enter ]" << endl;
            cin.get();
            cin.get();
        }
    }
}
void SetUserInfo(vector<Player*>& playerList, int playerIndex)
{
    string userNameInput;
    int userAgeInput;

    std::system("cls");
    cout << "==========================" << endl;
    cout << "[ ������ �Է��ϼ���. ]" << endl;
    cout << "==========================" << endl;

    cout << "�Է� >> ";
    cin >> userNameInput;
    
    std::system("cls");
    cout << "==========================" << endl;
    cout << "[ ���̸� �Է��ϼ���. ]" << endl;
    cout << "==========================" << endl;

    cout << "�Է� >> ";
    cin >> userAgeInput;

    playerList[playerIndex]->SetUserInfo(userNameInput, userAgeInput);

    std::system("cls");
    playerList[playerIndex]->PrintUserInfo();

    cout << "[ Ȯ��: Enter ]" << endl;
    cin.get();
    cin.get();

    return;
}
void SetCharInfo(vector<Player*>& playerList, int playerIndex)
{
    string userInput;

    std::system("cls");
    cout << "==========================" << endl;
    cout << "[ �г����� �Է��ϼ���. ]" << endl;
    cout << "==========================" << endl;

    cout << "�Է� >> ";
    cin >> userInput;
    playerList[playerIndex]->SetName(userInput);

    std::system("cls");
    cout << "==========================" << endl;
    cout << "[ ĳ���� ���� �Ϸ� ]" << endl;
    cout << "==========================" << endl;
    playerList[playerIndex]->PrintInfo();

    cout << "[ ȸ�� ���� 1���� ���޵Ǿ����ϴ�. ]" << endl;
    playerList[playerIndex]->AddItem("ȸ�� ����");

    cout << "[ Ȯ��: Enter ]" << endl;
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

// Menu
void InventoryUseMenu(Player* player)
{
    int sel = 0;

    while (true)
    {
        std::system("cls");
        cout << "==========================" << endl;
        cout << "[ ������ ��� ]" << endl;
        player->PrintInventory();
        cout << "[ 9. ���ư��� ]" << endl;
        cout << "==========================" << endl;

        cout << "���� >> ";
        cin >> sel;

        switch (sel)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            player->UseInventoryItem(sel);
            cout << "[ Ȯ��: Enter ]" << endl;
            cin.get();
            cin.get();
            break;
        case 9:
            std::system("cls");
            return;
        }
    }

}
void InventoryMenu(Player* player)
{
    int userInventorySel = 0;
    int userInventoryListSel = 0;

    while (true)
    {
        std::system("cls");
        cout << "==========================" << endl;
        cout << "[ �κ��丮 ]" << endl;
        cout << "==========================" << endl;
        cout << "[ 1. ������ ��� ]" << endl;
        cout << "[ 2. ������ ��� ]" << endl;
        cout << "[ 0. ���ư��� ]" << endl;
        cout << "==========================" << endl;
        cout << "���� >> ";
        cin >> userInventorySel;

        switch (userInventorySel)
        {
        case 1:
            player->PrintInventory();
            cout << "[ Ȯ��: Enter ]" << endl;
            cin.get();
            cin.get();
            break;
        case 2:
            InventoryUseMenu(player);
            break;
        case 0:
            std::system("cls");
            return;
        }
    }
}
void ShopBuyMenu(Player* player)
{
    int sel = 0;

    while (true)
    {
        std::system("cls");
        cout << "==========================" << endl;
        cout << "[ �Ǹ� ��� ]" << endl;
        shop->PrintShopList();
        cout << "[ 9. ���ư��� ]" << endl;
        cout << "==========================" << endl;
        
        cout << "���� >> ";
        cin >> sel;

        switch (sel)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            shop->BuyItem(player, sel);
            cout << "[ Ȯ��: Enter ]" << endl;
            cin.get();
            cin.get();
            break;
        case 9:
            std::system("cls"); return;
        }
    }
    
}
void ShopMenu(Player* player)
{
    int sel = 0;

    std::system("cls");
    
    while (true)
    {
        cout << "==========================" << endl;
        cout << "[ ���� ]" << endl;
        cout << "[ 1. ������ ���� ]" << endl;
        cout << "[ 2. ������ �Ǹ�(�̱���) ]" << endl;
        cout << "[ 0. ���ư��� ]" << endl;
        cout << "==========================" << endl;
        cout << "���� >> ";
        cin >> sel;

        switch (sel)
        {
        case 1:
            ShopBuyMenu(player);
            break;
        case 2:
        case 0:
            std::system("cls");
            return;
        }
    }
}
void TownMenu(Player* player)
{
    int sel = 0;

    while (true)
    {
        std::system("cls");
        cout << "==========================" << endl;
        cout << "[ ���� ]" << endl;
        cout << "==========================" << endl;
        cout << "[ 1. �κ��丮 ]" << endl;
        cout << "[ 2. �������� ]" << endl;
        cout << "[ 0. ���ư��� ]" << endl;
        cout << "==========================" << endl;
        cout << "���� >> ";
        cin >> sel;

        switch (sel)
        {
        case 1:
            InventoryMenu(player);
            break;
        case 2:
            ShopMenu(player);
            break;
        case 0:
            std::system("cls");
            return;
        }

    }
}
void CombatMenu(Player* player, Monster* monster)
{
    int sel;

    while (true)
    {
        std::system("cls");
        cout << "==========================" << endl;
        cout << "[ ���� ]" << endl;
        cout << "==========================" << endl;
        cout << "[ 1. �Ϲ� ���� ]" << endl;
        cout << "[ 2. ��ų 1 ]" << endl;
        cout << "[ 3. ��ų 2 ]" << endl;
        cout << "[ 4. ��ų 3 ]" << endl;
        cout << "[ 0. ������ ]" << endl;
        cout << "==========================" << endl;

        cout << "�Է� >> ";
        cin >> sel;

        switch (sel)
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
        case 0:
            TownMenu(player);
            break;
        }

        if (sel != 0)
        {
            if (!monster->GetAlive())
            {
                cout << "[ ���� ���� : �¸�]" << endl;
                cout << "[ Ȯ��: Enter ]" << endl;
                cin.get();
                cin.get();
                return;
            }
            cout << "[ " << monster->GetName() << " HP : " << monster->GetHp() << " ]" << endl;

            monster->Attack(player);
            if (!player->GetAlive())
            {
                cout << "[ ���� ���� : �й�] " << endl;
                cout << "[ Ȯ��: Enter ]" << endl;
                cin.get();
                cin.get();
                return;
            }
            cout << "[ " << player->GetName() << " HP : " << player->GetHp() << " ]" << endl;

            cout << "[ Ȯ��: Enter ]" << endl;
            cin.get();
            cin.get();
        }
    }
}

// Scene
void Chapter1(Player* player, int* _progress)
{ 
    Monster* monster = NULL;

    while (*_progress == 1)
    {
        monster = new Monster("ŷ ������");
        system("cls");
        std::cout << "==========================" << std::endl;
        std::cout << "Chapter " << *_progress << std::endl;
        std::cout << "[ŷ ������ ���]" << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << "�Ŵ��� �������� �ĵ��Դ� �̤�" << std::endl;

        cin.get();
        CombatMenu(player, monster);

        if (monster->GetAlive() == false
            && player->GetAlive() == true)
        {
            delete(monster);
            std::cout << "==========================" << std::endl;
            std::cout << "Chapter " << *_progress << std::endl;
            std::cout << "[ŷ ������ ���] Ŭ����" << std::endl;
            std::cout << "==========================" << std::endl;
            
            *_progress = *_progress + 1;
            cin.get();
            return;
        }

        else
        {
            delete(monster);
            cout << "Game Over" << endl;
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
        // Init
        CreatePlayer(playerList, player);
        SetCharInfo(playerList, 0);
        SetUserInfo(playerList, 0);

        // MainStream
        Chapter1(playerList[0], progress);
        Chapter2(playerList[0], progress);

    case 2:
        return 0;
    }
    
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