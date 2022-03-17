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
#include "Forge.h"
#include "HpPotion.h"
#include "MpPotion.h"
#include "Sword.h"

using namespace std;

// global
string gameTitle = "������ ������";
Shop* shop = new Shop();
Forge* forge = new Forge();

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
    cout << endl;
    cout << "���� >> ";
}
void InputPrint()
{
    setColor(GREEN);
    cout << endl;
    cout << "�Է� >> ";
}

// init
int StartGame()
{
    int userSel;
    
    while (true)
    {
        tryAgain:
        std::system("cls");
        setColor(YELLOW);
        cout << "==========================" << endl;
        cout << " [ " << gameTitle << " ]" << endl;
        cout << "==========================" << endl;
        setColor(SKYBLUE);
        cout << " [ 1. ���� ���� ]" << endl;
        cout << " [ 2. ���� ���� ]" << endl;
        SelectPrint();

        cin >> userSel;

        if (isdigit(userSel) || (userSel < 1) || (userSel > 2))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "WARNING: WRONG INPUT" << endl;
            GetOneBuffer();
            goto tryAgain;
        }

        switch (userSel)
        {
        case 1: 
        case 2: return userSel;
        }
    }
}
void CreatePlayer(vector<Player*>& playerList, Player*& player)
{
    int userSel;

    while (true)
    {
        std::system("cls");
        setColor(YELLOW);
        cout << "==========================" << endl;
        cout << " [ ������ �����ϼ���. ]" << endl;
        cout << "==========================" << endl;
        setColor(SKYBLUE);
        cout << " [ 1. ���� ]" << endl;
        cout << " [ 2. ������ ]" << endl;
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
    setColor(YELLOW);
    cout << "==========================" << endl;
    cout << " [ ������ �Է��ϼ���. ]" << endl;
    cout << "==========================" << endl;

    InputPrint();
    cin >> userNameInput;

    setColor(YELLOW);
    cout << "==========================" << endl;
    cout << " [ ���̸� �Է��ϼ���. ]" << endl;
    cout << "==========================" << endl;

    InputPrint();
    cin >> userAgeInput;

    playerList[playerIndex]->SetUserInfo(userNameInput, userAgeInput);

    std::system("cls");
    setColor(YELLOW);
    cout << "==========================" << endl;
    cout << " [ ���� ���� ]" << endl;
    cout << "==========================" << endl;
    playerList[playerIndex]->PrintUserInfo();

    GetTwoBuffer();

    return;
}
void SetCharInfo(vector<Player*>& playerList, int playerIndex)
{
    string userInput;

    std::system("cls");
    setColor(YELLOW);
    cout << "==========================" << endl;
    cout << " [ �г����� �Է��ϼ���. ]" << endl;
    cout << "==========================" << endl;

    InputPrint();
    cin >> userInput;
    playerList[playerIndex]->SetName(userInput);

    std::system("cls");
    playerList[playerIndex]->PrintInfo();
    cout << " [ ȸ�� ���� 1���� ���޵Ǿ����ϴ�. ]" << endl;
    cout << " [ ���� ���� 1���� ���޵Ǿ����ϴ�. ]" << endl;
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
void InitForge()
{
    forge->AddItem(new Sword(999));
}

// Menu
void InventoryUseMenu(Player* player)
{
    int sel = 0;

    while (true)
    {
        std::system("cls");
        setColor(YELLOW);
        cout << "==========================" << endl;
        cout << " [ ������ ��� ]" << endl;
        cout << "==========================" << endl;
        setColor(SKYBLUE);
        player->PrintInventory();
        cout << " [ 9. ���ư��� ]" << endl;

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
        setColor(YELLOW);
        cout << "==========================" << endl;
        cout << " [ �κ��丮 ]" << endl;
        cout << "==========================" << endl;
        setColor(SKYBLUE);
        cout << " [ 1. ������ ��� ]" << endl;
        cout << " [ 2. ������ ��� ]" << endl;
        cout << " [ 0. ���ư��� ]" << endl;
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
void ForgeBuyMenu(Player* player)
{
    int sel = 0;

    while (true)
    {
        std::system("cls");
        setColor(YELLOW);
        cout << "==========================" << endl;
        cout << " [ �Ǹ� ��� ]" << endl;
        cout << " [ ������ : " << player->GetGold() << " ]" << endl;
        cout << "==========================" << endl;
        setColor(SKYBLUE);
        forge->PrintShopList();
        cout << " [ 9. ���ư��� ]" << endl;

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
            forge->BuyItem(player, sel);
            GetTwoBuffer();
            break;
        case 9:
            std::system("cls"); return;
        }
    }

}
void ForgeHoningMenu(Player* player)
{
    int sel = 0;

    while (true)
    {
        std::system("cls");
        setColor(YELLOW);
        cout << "==========================" << endl;
        cout << " [ ��� ��� ]" << endl;
        cout << " [ ������ : " << player->GetGold() << " ]" << endl;
        cout << "==========================" << endl;
        setColor(SKYBLUE);
        player->PrintInventoryEquipment();
        cout << " [ 9. ���ư��� ]" << endl;

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
            forge->HoningItem(player, sel);
            GetTwoBuffer();
            break;
        case 9:
            std::system("cls"); return;
        }
    }

}
void ForgeMenu(Player* player)
{
    int sel = 0;

    std::system("cls");

    while (true)
    {
        setColor(YELLOW);
        cout << "==========================" << endl;
        cout << " [ ���尣 ]" << endl;
        cout << "==========================" << endl;
        setColor(SKYBLUE);
        cout << " [ 1. ��� ���� ]" << endl;
        cout << " [ 2. ������ ��� ]" << endl;
        cout << " [ 0. ���ư��� ]" << endl;
        SelectPrint();
        cin >> sel;

        switch (sel)
        {
        case 1:
            ForgeBuyMenu(player);
            break;
        case 2:
            ForgeHoningMenu(player);
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
        setColor(YELLOW);
        cout << "==========================" << endl;
        cout << "[ �Ǹ� ��� ]" << endl;
        cout << "[ ������ : " << player->GetGold() << " ]" << endl;
        cout << "==========================" << endl;
        setColor(SKYBLUE);
        shop->PrintShopList();
        cout << "[ 9. ���ư��� ]" << endl;
        
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
        setColor(YELLOW);
        cout << "==========================" << endl;
        cout << " [ ������� ]" << endl;
        cout << "==========================" << endl;
        setColor(SKYBLUE);
        cout << " [ 1. ���� ���� ]" << endl;
        cout << " [ 2. �Ǹ�(�̱���) ]" << endl;
        cout << " [ 0. ���ư��� ]" << endl;
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
        setColor(YELLOW);
        cout << "==========================" << endl;
        cout << " [ ���� ]" << endl;
        cout << "==========================" << endl;
        setColor(SKYBLUE);
        cout << " [ 1. �κ��丮 ]" << endl;
        cout << " [ 2. ������� ]" << endl;
        cout << " [ 3. ���尣 ]" << endl;
        cout << " [ 4. �������� ]" << endl;
        cout << " [ 0. ���ư��� ]" << endl;
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
        case 3:
            ForgeMenu(player);
            break;
        case 4:
            exit(0);
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
        setColor(YELLOW);
        cout << "===============================" << endl;
        cout << " [ ���� ]" << endl;
        cout << "===============================" << endl;
        setColor(RED);
        cout << " [ " << player->GetTitle() << " " << player->GetName() << "�� �������ͽ� ]" << endl;
        cout << " [ HP: " << player->GetHp() << " / " << "MP: " << player->GetMp() << " / " << "��ȣ��: " << player->GetShield() << " ]" << endl;
        cout << " [ ���ݷ�: " << player->GetDmg() << "(+" << player->GetDmgBuff() << ")"
            << " / " << "����: " << player->GetDef() << "(+" << player->GetDefBuff() << ")" " ]" << endl;
        setColor(YELLOW);
        cout << "===============================" << endl;
        setColor(BLUE);
        cout << " [ " << monster->GetName() << "�� �������ͽ� ]" << endl;
        cout << " [ HP: " << monster->GetHp() << " / " << "��ȣ��: " << monster->GetShield() << " ]" << endl;
        cout << " [ ���ݷ�: " << monster->GetDmg() << "(+" << monster->GetDmgBuff() << ")"
            << " / " << "����: " << monster->GetDef() << "(+" << monster->GetDefBuff() << ")" " ]" << endl;
        setColor(YELLOW);
        cout << "===============================" << endl;
        cout << " [ 1. �Ϲ� ���� ]" << endl;
        cout << " [ 2. " << player->GetSkillNameA() << " ]" << endl;
        cout << " [ 3. " << player->GetSkillNameB() << " ]" << endl;
        cout << " [ 4. " << player->GetSkillNameC() << " ]" << endl;
        cout << " [ 0. ������ ]" << endl;
        
        SelectPrint();
        cin >> sel;

        // �÷��̾� ��
        if (sel != 0)
        {
            setColor(RED);
            cout << " ��[ �÷��̾� �� ]" << endl;

            if (player->GetStunCnt() > 0)
            {
                setColor(RED);
                player->TurnManager();
                cout << " [ �÷��̾ �����Ұ� �����Դϴ�. ("
                    << monster->GetStunCnt() << "��) ]" << endl;

                sel = 1;
                goto skipPlayerTurn;
            }
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
            cout << " [ ���� ���� : �¸�]" << endl;
            GetTwoBuffer();
            return;
        }

        // ���� ��
        setColor(BLUE);
        cout << " ��[ ���� �� ]" << endl;
        if (monster->GetStunCnt() > 0)
        {
            monster->TurnManager();
            cout << " [ " << monster->GetName() << "�� �����Ұ� �����Դϴ�. ("
                << monster->GetStunCnt() << "��) ]" << endl;

            sel = 1;
            goto skipMonsterTurn;
        }
        
        monster->RandomAttack(player);

        skipMonsterTurn:

        if (!player->GetAlive())
        {
            setColor(BLUE);
            cout << " [ ���� ���� : �й�] " << endl;
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
    setColor(YELLOW);
    std::cout << "==========================" << std::endl;
    std::cout << " [ Game Over ] " << endl;
    std::cout << "==========================" << std::endl;
    setColor(SKYBLUE);
    cout << " [ ������ ���ѳ� �� ������. ]" << endl;
    GetOneBuffer();
    exit(0);

    return;
}
void Prologue()
{
    system("cls");
    setColor(YELLOW);
    std::cout << "==========================" << std::endl;
    std::cout << " [ Prologue ] " << endl;
    std::cout << "==========================" << std::endl;
    setColor(SKYBLUE);
    cout << " [ ��ȯ���� ����� ������ �����Ⱑ �����Ѵ�. ]" << endl;
    cout << " [ ����� ���ݺ��� �� ��������� û���ؾ� �Ѵ�. ]" << endl;
    GetOneBuffer();

    return;
}
void Chapter1(Player* player, int* _progress)
{ 
    Monster* monster = NULL;

    while (*_progress == 1)
    {
        monster = new LUX();
        system("cls");
        setColor(YELLOW);
        std::cout << "==========================" << std::endl;
        std::cout << " Chapter " << *_progress << std::endl;
        std::cout << " [���� ����]" << std::endl;
        std::cout << "==========================" << std::endl;
        setColor(SKYBLUE);
        std::cout << " \"������ CS�� ���ֳ׿뤾\" " << std::endl;

        GetCombatBuffer();
        CombatMenu(player, monster);

        if (monster->GetAlive() == false
            && player->GetAlive() == true)
        {
            system("cls");
            setColor(YELLOW);
            std::cout << "==========================" << std::endl;
            std::cout << " Chapter " << *_progress << std::endl;
            std::cout << " [���� ����] Ŭ����!" << std::endl;
            std::cout << "==========================" << std::endl;
            setColor(SKYBLUE);
            std::cout << " \"��������\" " << endl;
            monster->DropItem(player);
            delete(monster);
            
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
        setColor(YELLOW);
        std::cout << "==========================" << std::endl;
        std::cout << " Chapter " << *_progress << std::endl;
        std::cout << " [ž ����]" << std::endl;
        std::cout << "==========================" << std::endl;
        setColor(SKYBLUE);
        std::cout << " \"�� �ȿ��� ���� ����\" " << std::endl;

        GetCombatBuffer();
        CombatMenu(player, monster);

        if (monster->GetAlive() == false
            && player->GetAlive() == true)
        {
            system("cls");
            setColor(YELLOW);
            std::cout << "==========================" << std::endl;
            std::cout << " Chapter " << *_progress << std::endl;
            std::cout << " [ž ����] Ŭ����!" << std::endl;
            std::cout << "==========================" << std::endl;
            setColor(SKYBLUE);
            std::cout << " \"�շ� ���� �˾Ƽ� �ϼ�\" " << endl;
            monster->DropItem(player);
            delete(monster);

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
        setColor(YELLOW);
        std::cout << "==========================" << std::endl;
        std::cout << " Chapter " << *_progress << std::endl;
        std::cout << " [�̵� �߽���]" << std::endl;
        std::cout << "==========================" << std::endl;
        setColor(SKYBLUE);
        std::cout << " \"�� ���� ���׳�\" " << std::endl;

        GetCombatBuffer();
        CombatMenu(player, monster);

        if (monster->GetAlive() == false
            && player->GetAlive() == true)
        {
            system("cls");
            setColor(YELLOW);
            std::cout << "==========================" << std::endl;
            std::cout << " Chapter " << *_progress << std::endl;
            std::cout << " [�̵� �߽���] Ŭ����!" << std::endl;
            std::cout << "==========================" << std::endl;
            setColor(SKYBLUE);
            std::cout << " \"�� �̵� ����\" " << endl;
            monster->DropItem(player);
            delete(monster);

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
        setColor(YELLOW);
        std::cout << "==========================" << std::endl;
        std::cout << " Chapter " << *_progress << std::endl;
        std::cout << " [���� ��������]" << std::endl;
        std::cout << "==========================" << std::endl;
        setColor(SKYBLUE);
        std::cout << " \"���� ��Ƽ�� ���常 �ϰ� ��\" " << std::endl;

        GetCombatBuffer();
        CombatMenu(player, monster);

        if (monster->GetAlive() == false
            && player->GetAlive() == true)
        {
            system("cls");
            setColor(YELLOW);
            std::cout << "==========================" << std::endl;
            std::cout << " Chapter " << *_progress << std::endl;
            std::cout << " [���� ��������] Ŭ����!" << std::endl;
            std::cout << "==========================" << std::endl;
            setColor(SKYBLUE);
            std::cout << " \"�˷��൵ ������ ��\" " << endl;
            monster->DropItem(player);
            delete(monster);

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
    setColor(YELLOW);
    std::cout << "==========================" << std::endl;
    std::cout << " [ Epilogue ] " << endl;
    std::cout << "==========================" << std::endl;
    setColor(SKYBLUE);
    cout << " [ ����� ������ ��´��� ]" << endl;
    cout << " [ ��ȯ���� ����� ��ȭ�� ã�ƿԴ�. ]" << endl;

    GetOneBuffer();

    return;
}

// --------------------------------- Main
int main()
{
    Player* player = NULL;
    Monster* monster = NULL;
    vector<Player*> playerList;
    vector<Monster*> monsterList;
    int* StoryProgress = new int(1);
    int sel = 0;

    sel = StartGame();

    switch (sel)
    {
    case 1:
        // Init
        CreatePlayer(playerList, player);
        SetCharInfo(playerList, 0);
        SetUserInfo(playerList, 0);
        InitShop();
        InitForge();

        // MainStream
        Prologue();
        Chapter1(playerList[0], StoryProgress);
        Chapter2(playerList[0], StoryProgress);
        Chapter3(playerList[0], StoryProgress);
        Chapter4(playerList[0], StoryProgress);
        Epilogue();

    case 2:
        return 0;
    }

    delete player;
    delete monster;
    delete shop;
    delete StoryProgress;
    
    return 0;
}