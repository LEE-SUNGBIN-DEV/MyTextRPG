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
    cout << "　" << gameTitle << endl;
    cout << "==========================" << endl;
    cout << "1. 게임 시작" << endl;
    cout << "2. 게임 종료" << endl;
    cout << "선택 >> ";

    cin >> titleSel;

    return titleSel;
}
void CreatePlayer(vector<Player*>& playerList, Player*& player)
{
    int typeSel;

    system("cls");
    cout << "==========================" << endl;
    cout << "직업을 선택하세요." << endl;
    cout << "1. 전사" << endl;
    cout << "2. 마법사" << endl;
    cout << "==========================" << endl;
    
    while (true)
    {
        cout << "선택 >> ";
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
    cout << "성함을 입력하세요." << endl;
    cout << "==========================" << endl;

    cout << "입력 >> ";
    cin >> playerStrInput;
    
    system("cls");
    cout << "==========================" << endl;
    cout << "나이를 입력하세요." << endl;
    cout << "==========================" << endl;

    cout << "입력 >> ";
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
    cout << "닉네임을 입력하세요." << endl;
    cout << "==========================" << endl;

    cout << "입력 >> ";
    cin >> playerStrInput;
    playerList[playerIndex]->SetName(playerStrInput);

    system("cls");
    cout << "==========================" << endl;
    cout << "캐릭터 세팅 완료" << endl;
    cout << "==========================" << endl;
    playerList[playerIndex]->PrintInfo();

    playerList[playerIndex]->AddItem("회복물약");
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
        cout << "(몬스터 생성) 목록: 슬라임, 고블린, 드래곤 / X: 종료" << endl;
        cout << "----------------------------------------------------" << endl;
        cin >> monSel;
        if (monSel == "슬라임" || monSel == "고블린" || monSel == "드래곤")
        {
            monster = new Monster(monSel);
            monsterList.push_back(monster);
            cout << monSel << " " << "생성 완료" << endl;
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
void InventoryMenu(Player* player)
{
    int invenSel = 0;
    int itemSel = 0;

    system("cls");
    cout << "==========================" << endl;
    cout << " 인벤토리" << endl;
    cout << "==========================" << endl;
    cout << " 1. 아이템 목록 보기" << endl;
    cout << " 2. 아이템 사용" << endl;
    cout << " 0. 돌아가기" << endl;
    cout << "==========================" << endl;

    while (true)
    {
        cout << "입력 >> ";
        cin >> invenSel;

        switch (invenSel)
        {
        case 1:
            player->PrintInventory();
            break;
        case 2:
            cout << "사용할 슬롯 번호 입력 >> ";
            cin >> itemSel;
            player->UseInventoryItem(itemSel);
            break;
        case 0:
            return;
        }
    }
}
void ShopMenu(Player* player)
{
    int shopSel = 0;

    system("cls");
    cout << "==========================" << endl;
    cout << " 상점" << endl;
    cout << "==========================" << endl;
    cout << " 1. 회복 물약" << endl;
    cout << " 2. 마나 물약" << endl;
    cout << " 0. 돌아가기" << endl;
    cout << "==========================" << endl;

    while (true)
    {
        cout << "구매 >> ";
        cin >> shopSel;

        switch (shopSel)
        {
        case 1:
            break;
        case 2:
            break;
        case 0:
            return;
        }
    }
}
void TownMenu(Player* player)
{
    int townSel = 0;

    system("cls");

    while (true)
    {
        cout << "==========================" << endl;
        cout << " 마을 메뉴" << endl;
        cout << "==========================" << endl;
        cout << " 1. 인벤토리" << endl;
        cout << " 2. 상점으로" << endl;
        cout << " 0. 돌아가기" << endl;
        cout << "==========================" << endl;
        cout << "입력 >> ";
        cin >> townSel;

        switch (townSel)
        {
        case 1:
            InventoryMenu(player);
            system("cls");
            break;
        case 2:
            ShopMenu(player);
            system("cls");
            break;
        case 0:
            return;
        }

    }
}
void CombatMenu(Player* player, Monster* monster)
{
    int combatSel = 0;

    system("cls");

    while (true)
    {
        if (combatSel == 0)
        {
            cout << "==========================" << endl;
            cout << " 전투 메뉴" << endl;
            cout << "==========================" << endl;
            cout << " 1. 일반 공격" << endl;
            cout << " 2. 스킬 1" << endl;
            cout << " 3. 스킬 2" << endl;
            cout << " 4. 스킬 3" << endl;
            cout << " 0. 마을로" << endl;
            cout << "==========================" << endl;
        }
        cout << "입력 >> ";
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
        case 0:
            TownMenu(player);
            system("cls");
            break;
        }

        if (combatSel != 0)
        {
            if (!monster->GetAlive())
            {
                cout << "[ 전투 종료 ]" << endl;
                return;
            }
            cout << "[ " << monster->GetName() << " HP : " << monster->GetHp() << " ]" << endl;

            monster->Attack(player);
            if (!player->GetAlive())
            {
                cout << "[ 전투 종료] " << endl;
                return;
            }
            cout << "[ " << player->GetName() << " HP : " << player->GetHp() << " ]" << endl;
        }
    }
}

// Scene
void Chapter1(Player* player, int* _progress)
{ 
    Monster* monster = NULL;

    while (*_progress == 1)
    {
        monster = new Monster("슬라임");
        system("cls");
        std::cout << "==========================" << std::endl;
        std::cout << "Chapter " << *_progress << std::endl;
        std::cout << "[슬라임 사냥]" << std::endl;
        std::cout << "==========================" << std::endl;

        cin.get();
        CombatMenu(player, monster);

        if (monster->GetAlive() == false
            && player->GetAlive() == true)
        {
            std::cout << "==========================" << std::endl;
            std::cout << "Chapter " << *_progress << std::endl;
            std::cout << "[슬라임 사냥] 클리어" << std::endl;
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
        SetCharInfo(playerList, 0);
        SetUserInfo(playerList, 0);

        Chapter1(playerList[0], progress);
        Chapter2(playerList[0], progress);

    case 2:
        return 0;
    }
    
    //

    return 0;
}

// 닉네임 탐색해서 일치하는 닉네임 존재시 해당 "인덱스" 반환
int FindNicknameIndex(vector<Player*> playerList, string nick)
{
    cout << "-------------------------------------" << endl;
    cout << "닉네임: " << nick << "을(를) 탐색합니다." << endl;

    for (int i = 0; i < playerList.size(); i++)
    {
        if (nick == playerList[i]->GetName())
        {
            cout << "일치하는 플레이어가 존재합니다." << endl;
            cout << "IndexNum: " << i << endl;
            cout << "-------------------------------------" << endl;

            return i;
        }
    }
    cout << "일치하는 플레이어가 존재하지 않습니다." << endl;
    cout << "-------------------------------------" << endl;

    return -1;
}

// 닉네임 탐색해서 일치하는 닉네임 존재시 플레이어 정보 "출력"
void PrintSearchPlayer(vector<Player*> playerList, int index)
{
    if (index == -1)
        return;

    else
    {
        cout << "해당 플레이어의 정보" << endl;
        playerList[index]->PrintInfo();
    }
}