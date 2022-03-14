#include <iostream>
#include <string>
#include <vector>
#include <Windows.h> // system()

#include "Character.h"
#include "Monster.h"
#include "LUX.h"
#include "Vayne.h"
#include "Yasuo.h"
#include "MasterYi.h"

#include "Player.h"
#include "Knight.h"
#include "Wizard.h"

#include "Shop.h"
#include "HpPotion.h"
#include "MpPotion.h"

using namespace std;

// global
string gameTitle = "������ ������";
Shop* shop = new Shop();

// Input Control
void GetCombatBuffer()
{
    setColor(GREEN);
    cout << endl;
    cout << "�� [ ȥ������ : Enter ]" << endl;
    cin.get();
}
void GetOneBuffer()
{
    setColor(GREEN);
    cout << endl;
    cout << "�� [ Ȯ��: Enter ]" << endl;
    cin.get();
}
void GetTwoBuffer()
{
    setColor(GREEN);
    cout << endl;
    cout << "�� [ Ȯ��: Enter ]" << endl;
    cin.get();
    cin.get();
}
void SelectPrint()
{
    setColor(GREEN);
    cout << "���� >> ";
}
void InputPrint()
{
    setColor(GREEN);
    cout << "�Է� >> ";
}

// init
int MainTitle()
{
    int userSel;
    
    while (true)
    {
        std::system("cls");
        setColor(YELLOW);
        cout << "============================" << endl;
        cout << "��[" << gameTitle << " ]" << endl;
        cout << "============================" << endl;
        setColor(GREEN);
        cout << "[ 1. ���� ���� ]" << endl;
        cout << "[ 2. ���� ���� ]" << endl;
        SelectPrint();

        cin >> userSel;

        if (userSel == 1 || userSel == 2)
        {
            return userSel;
        }

        else
        {
            cout << "ERROR: WRONG INPUT: MainTitle()" << endl;
            GetTwoBuffer();
        }
    }
}
void CreatePlayer(vector<Player*>& playerList, Player*& player)
{
    int userSel;

    while (true)
    {
        std::system("cls");
        setColor(SKYBLUE);
        cout << "====================================" << endl;
        cout << "[ ������ �����ϼ���. ]" << endl;
        setColor(YELLOW);
        cout << "====================================" << endl;
        cout << "[ 1. ���� ]" << endl;
        cout << "[ 2. ������ ]" << endl;
        cout << "====================================" << endl;
        SelectPrint();

        cin >> userSel;

        switch (userSel)
        {
        case ENUM_PLAYER_KNIGHT:
            player = new Knight();
            playerList.push_back(player);
            return;

        case ENUM_PLAYER_WIZARD:
            player = new Wizard();
            playerList.push_back(player);
            return;
        }
    }
}
void SetUserInfo(vector<Player*>& playerList, int playerIndex)
{
    string userNameInput;
    int userAgeInput;

    std::system("cls");
    setColor(SKYBLUE);
    cout << "====================================" << endl;
    cout << "[ ������ �Է��ϼ���. ]" << endl;
    cout << "====================================" << endl;

    InputPrint();
    cin >> userNameInput;

    setColor(SKYBLUE);
    cout << "====================================" << endl;
    cout << "[ ���̸� �Է��ϼ���. ]" << endl;
    cout << "====================================" << endl;

    InputPrint();
    cin >> userAgeInput;

    playerList[playerIndex]->SetUserInfo(userNameInput, userAgeInput);

    std::system("cls");
    setColor(SKYBLUE);
    cout << "==========================" << endl;
    cout << "[ ���� ���� ]" << endl;
    playerList[playerIndex]->PrintUserInfo();

    GetTwoBuffer();

    return;
}
void SetCharInfo(vector<Player*>& playerList, int playerIndex)
{
    string userInput;

    std::system("cls");
    setColor(SKYBLUE);
    cout << "====================================" << endl;
    cout << "[ �г����� �Է��ϼ���. ]" << endl;
    cout << "====================================" << endl;

    InputPrint();
    cin >> userInput;
    playerList[playerIndex]->SetName(userInput);

    std::system("cls");
    setColor(SKYBLUE);
    cout << "====================================" << endl;
    cout << "[ ĳ���� ���� �Ϸ� ]" << endl;
    cout << "====================================" << endl;
    playerList[playerIndex]->PrintInfo();
    setColor(RED);
    cout << "====================================" << endl;
    cout << "[ ȸ�� ���� 1���� ���޵Ǿ����ϴ�. ]" << endl;
    cout << "[ ���� ���� 1���� ���޵Ǿ����ϴ�. ]" << endl;
    playerList[playerIndex]->AddItem(new HpPotion(1));
    playerList[playerIndex]->AddItem(new MpPotion(1));

    GetTwoBuffer();

    return;
}
void InitShop()
{
    shop->AddItem(new HpPotion(999));
    shop->AddItem(new MpPotion(999));
}

// Menu
void InventoryUseMenu(Player* player)
{
    int sel = 0;

    while (true)
    {
        std::system("cls");
        setColor(SKYBLUE);
        cout << "==========================" << endl;
        cout << "[ ������ ��� ]" << endl;
        setColor(YELLOW);
        cout << "==========================" << endl;
        player->PrintInventory();
        cout << "[ 9. ���ư��� ]" << endl;
        cout << "==========================" << endl;

        SelectPrint();
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
            GetTwoBuffer();
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
        setColor(SKYBLUE);
        cout << "==========================" << endl;
        cout << "[ �κ��丮 ]" << endl;
        setColor(YELLOW);
        cout << "==========================" << endl;
        cout << "[ 1. ������ ��� ]" << endl;
        cout << "[ 2. ������ ��� ]" << endl;
        cout << "[ 0. ���ư��� ]" << endl;
        cout << "==========================" << endl;
        SelectPrint();
        cin >> userInventorySel;

        switch (userInventorySel)
        {
        case 1:
            player->PrintInventory();
            GetTwoBuffer();
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
        setColor(SKYBLUE);
        cout << "==========================" << endl;
        cout << "[ �Ǹ� ��� ]" << endl;
        cout << "[ ������ : " << player->GetGold() << " ]" << endl;
        setColor(YELLOW);
        shop->PrintShopList();
        cout << "[ 9. ���ư��� ]" << endl;
        cout << "==========================" << endl;
        
        SelectPrint();
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
            GetTwoBuffer();
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
        setColor(SKYBLUE);
        cout << "==========================" << endl;
        cout << "[ ���� ]" << endl;
        setColor(YELLOW);
        cout << "==========================" << endl;
        cout << "[ 1. ������ ���� ]" << endl;
        cout << "[ 2. ������ �Ǹ�(�̱���) ]" << endl;
        cout << "[ 0. ���ư��� ]" << endl;
        cout << "==========================" << endl;
        SelectPrint();
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
        setColor(SKYBLUE);
        cout << "==========================" << endl;
        cout << "[ ���� ]" << endl;
        setColor(YELLOW);
        cout << "==========================" << endl;
        cout << "[ 1. �κ��丮 ]" << endl;
        cout << "[ 2. �������� ]" << endl;
        cout << "[ 0. ���ư��� ]" << endl;
        cout << "==========================" << endl;
        SelectPrint();
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
    tryAgain:
        std::system("cls");
        setColor(SKYBLUE);
        cout << "===============================" << endl;
        cout << "[ ���� ]" << endl;
        setColor(RED);
        cout << "===============================" << endl;
        cout << "[ " << player->GetName() << "�� �������ͽ� ]" << endl;
        cout << "[ HP: " << player->GetHp() << " / " << "MP: " << player->GetMp() << " / " << "��ȣ��: " << player->GetShield() << " ]" << endl;
        cout << "[ ���ݷ�: " << player->GetDmg() << "(+" << player->GetDmgBuff() << ")" << " / " << "����: " << player->GetDef() << " ]" << endl;
        setColor(BLUE);
        cout << "===============================" << endl;
        cout << "[ " << monster->GetName() << "�� �������ͽ� ]" << endl;
        cout << "[ HP: " << monster->GetHp() << " / " << "��ȣ��: " << monster->GetShield() << " ]" << endl;
        cout << "[ ���ݷ�: " << monster->GetDmg() << "(+" << monster->GetDmgBuff() << ")" << " / " << "����: " << monster->GetDef() << " ]" << endl;
        setColor(YELLOW);
        cout << "===============================" << endl;
        cout << "[ 1. �Ϲ� ���� ]" << endl;
        cout << "[ 2. " << player->GetSkillNameA() << " ]" << endl;
        cout << "[ 3. " << player->GetSkillNameB() << " ]" << endl;
        cout << "[ 4. " << player->GetSkillNameC() << " ]" << endl;
        cout << "[ 0. ������ ]" << endl;
        cout << "===============================" << endl;
        
        SelectPrint();
        cin >> sel;

        // �÷��̾� ��
        if (player->GetStunCnt() > 0 && sel != 0)
        {
            setColor(RED);
            cout << "[ �÷��̾ �����Ұ� �����Դϴ�. ] ";
            player->TurnManager();
            cout << "(" << monster->GetStunCnt() << "��)" << endl;
            
            sel = 1;
            goto skipPlayerTurn;
        }

        switch (sel)
        {
        case 1:
            player->Attack(monster);
            break;
        case 2:
            if (!player->SkillA(monster))
            {
                GetTwoBuffer();
                goto tryAgain;
            }
            break;
        case 3:
            if (!player->SkillB(monster))
            {
                GetTwoBuffer();
                goto tryAgain;
            }
            break;
        case 4:
            if (!player->SkillC(monster))
            {
                GetTwoBuffer();
                goto tryAgain;
            }
            break;
        case 0:
            TownMenu(player);
            goto tryAgain;
        }
        skipPlayerTurn:

        if (!monster->GetAlive())
        {
            setColor(RED);
            player->InitHp();
            player->InitMp();
            cout << "[ ���� ���� : �¸�]" << endl;
            GetTwoBuffer();
            return;
        }

        // ���� ��
        if (monster->GetStunCnt() > 0)
        {
            setColor(BLUE);
            cout << "[ " << monster->GetName() << "�� �����Ұ� �����Դϴ�. ] ";
            monster->TurnManager();
            cout << "(" << monster->GetStunCnt() << "��)" << endl;

            sel = 1;
            goto skipMonsterTurn;
        }
        
        monster->RandomAttack(player);

        skipMonsterTurn:

        if (!player->GetAlive())
        {
            setColor(BLUE);
            cout << "[ ���� ���� : �й�] " << endl;
            GetTwoBuffer();
            return;
        }
        
        GetTwoBuffer();
    }
}

// Scene
void GameOver()
{
    system("cls");
    setColor(SKYBLUE);
    std::cout << "==========================" << std::endl;
    std::cout << " [ Game Over ] " << endl;
    std::cout << "==========================" << std::endl;
    setColor(YELLOW);
    cout << "[ ������ ���ѳ� �� ������. ]" << endl;
    GetOneBuffer();
    exit(0);

    return;
}
void Prologue()
{
    system("cls");
    setColor(SKYBLUE);
    std::cout << "==========================" << std::endl;
    std::cout << " [ Prologue ] " << endl;
    std::cout << "==========================" << std::endl;
    setColor(YELLOW);
    cout << "[ ��ȯ���� ����� ������ �����Ⱑ �����Ѵ�. ]" << endl;
    cout << "[ ����� ���ݺ��� �� ��������� û���ؾ� �Ѵ�. ]" << endl;
    GetOneBuffer();
}
void Chapter1(Player* player, int* _progress)
{ 
    Monster* monster = NULL;

    while (*_progress == 1)
    {
        monster = new LUX();
        system("cls");
        setColor(SKYBLUE);
        std::cout << "==========================" << std::endl;
        std::cout << "Chapter " << *_progress << std::endl;
        std::cout << "[���� ����]" << std::endl;
        std::cout << "==========================" << std::endl;
        setColor(YELLOW);
        std::cout << " \"������ CS�� ���ֳ׿뤾\" " << std::endl;

        GetCombatBuffer();
        CombatMenu(player, monster);

        if (monster->GetAlive() == false
            && player->GetAlive() == true)
        {
            system("cls");
            setColor(SKYBLUE);
            std::cout << "==========================" << std::endl;
            monster->DropItem(player);
            delete(monster);
            setColor(SKYBLUE);
            std::cout << "==========================" << std::endl;
            std::cout << "Chapter " << *_progress << std::endl;
            std::cout << "[���� ����] Ŭ����" << std::endl;
            std::cout << "==========================" << std::endl;
            setColor(YELLOW);
            std::cout << " \"��������\" " << endl;
            
            *_progress = *_progress + 1;
            cin.get();
            return;
        }

        else
        {
            delete(monster);
            GameOver();
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
    Monster* monster = NULL;

    while (*_progress == 2)
    {
        monster = new Vayne();
        system("cls");
        setColor(SKYBLUE);
        std::cout << "==========================" << std::endl;
        std::cout << "Chapter " << *_progress << std::endl;
        std::cout << "[ž ����]" << std::endl;
        std::cout << "==========================" << std::endl;
        setColor(YELLOW);
        std::cout << " \"3�оȿ� �� �ȿ��� ���� ����\" " << std::endl;

        GetCombatBuffer();
        CombatMenu(player, monster);

        if (monster->GetAlive() == false
            && player->GetAlive() == true)
        {
            system("cls");
            setColor(SKYBLUE);
            std::cout << "==========================" << std::endl;
            monster->DropItem(player);
            delete(monster);
            setColor(SKYBLUE);
            std::cout << "==========================" << std::endl;
            std::cout << "Chapter " << *_progress << std::endl;
            std::cout << "[ž ����] Ŭ����" << std::endl;
            std::cout << "==========================" << std::endl;
            setColor(YELLOW);
            std::cout << " \"�շ� ���� �˾Ƽ� �ϼ���\" " << endl;

            *_progress = *_progress + 1;
            cin.get();
            return;
        }

        else
        {
            delete(monster);
            GameOver();
            return;
        }
    }

    if (*_progress != 2)
    {
        std::cout << "ERROR: WRONG ACCESS: MAIN STREAM CHAPTER " << *_progress << std::endl;
        return;
    }

    return;
}
void Chapter3(Player* player, int* _progress)
{
    Monster* monster = NULL;

    while (*_progress == 3)
    {
        monster = new Yasuo();
        system("cls");
        setColor(SKYBLUE);
        std::cout << "==========================" << std::endl;
        std::cout << "Chapter " << *_progress << std::endl;
        std::cout << "[�̵� �߽���]" << std::endl;
        std::cout << "==========================" << std::endl;
        setColor(YELLOW);
        std::cout << "[ �Ʊ��� ���߽��ϴ�. ]" << std::endl;
        std::cout << " \"�̾��� ��ħ?\" " << std::endl;

        GetCombatBuffer();
        CombatMenu(player, monster);

        if (monster->GetAlive() == false
            && player->GetAlive() == true)
        {
            system("cls");
            setColor(SKYBLUE);
            std::cout << "==========================" << std::endl;
            monster->DropItem(player);
            delete(monster);
            setColor(SKYBLUE);
            std::cout << "==========================" << std::endl;
            std::cout << "Chapter " << *_progress << std::endl;
            std::cout << "[�̵� �߽���] Ŭ����" << std::endl;
            std::cout << "==========================" << std::endl;
            setColor(YELLOW);
            std::cout << " \"�� �̵� ����\" " << endl;

            *_progress = *_progress + 1;
            cin.get();
            return;
        }

        else
        {
            delete(monster);
            GameOver();
            return;
        }
    }

    if (*_progress != 3)
    {
        std::cout << "ERROR: WRONG ACCESS: MAIN STREAM CHAPTER " << *_progress << std::endl;
        return;
    }

    return;
}
void Chapter4(Player* player, int* _progress)
{
    Monster* monster = NULL;

    while (*_progress == 4)
    {
        monster = new MasterYi();
        system("cls");
        setColor(SKYBLUE);
        std::cout << "==========================" << std::endl;
        std::cout << "Chapter " << *_progress << std::endl;
        std::cout << "[���� ��������]" << std::endl;
        std::cout << "==========================" << std::endl;
        setColor(YELLOW);
        std::cout << " \"���� ��Ƽ�� ���常 �ϰ� ��\" " << std::endl;

        GetCombatBuffer();
        CombatMenu(player, monster);

        if (monster->GetAlive() == false
            && player->GetAlive() == true)
        {
            system("cls");
            setColor(SKYBLUE);
            std::cout << "==========================" << std::endl;
            monster->DropItem(player);
            delete(monster);
            setColor(SKYBLUE);
            std::cout << "==========================" << std::endl;
            std::cout << "Chapter " << *_progress << std::endl;
            std::cout << "[���� ��������] Ŭ����" << std::endl;
            std::cout << "==========================" << std::endl;
            setColor(YELLOW);
            std::cout << " \"�˷��൵ ������ ��\" " << endl;

            *_progress = *_progress + 1;
            cin.get();
            return;
        }

        else
        {
            delete(monster);
            GameOver();
            return;
        }
    }

    if (*_progress != 4)
    {
        std::cout << "ERROR: WRONG ACCESS: MAIN STREAM CHAPTER " << *_progress << std::endl;
        return;
    }

    return;
}
void Epilogue()
{
    system("cls");
    setColor(SKYBLUE);
    std::cout << "==========================" << std::endl;
    std::cout << " [ Epilogue ] " << endl;
    std::cout << "==========================" << std::endl;
    setColor(YELLOW);
    cout << "[ ����� ������ ��´��� ]" << endl;
    cout << "[ ��ȯ���� ����� ��ȭ�� ã�ƿԴ�. ]" << endl;

    GetOneBuffer();

    return;
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
        InitShop();

        // MainStream
        Prologue();
        Chapter1(playerList[0], progress);
        Chapter2(playerList[0], progress);
        Chapter3(playerList[0], progress);
        Chapter4(playerList[0], progress);
        Epilogue();

    case 2:
        return 0;
    }

    delete player;
    delete monster;
    delete shop;
    delete progress;
    
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