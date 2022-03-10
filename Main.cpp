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
        cout << "　[" << gameTitle << " ]" << endl;
        cout << "==========================" << endl;
        cout << "[ 1. 게임 시작 ]" << endl;
        cout << "[ 2. 게임 종료 ]" << endl;
        cout << "선택 >> ";

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
            cout << "[ 확인: Enter ]" << endl;
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
        cout << "[ 직업을 선택하세요. ]" << endl;
        cout << "[ 1. 전사 ]" << endl;
        cout << "[ 2. 마법사 ]" << endl;
        cout << "==========================" << endl;
        cout << "선택 >> ";

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
            cout << "[ 확인: Enter ]" << endl;
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
    cout << "[ 성함을 입력하세요. ]" << endl;
    cout << "==========================" << endl;

    cout << "입력 >> ";
    cin >> userNameInput;
    
    std::system("cls");
    cout << "==========================" << endl;
    cout << "[ 나이를 입력하세요. ]" << endl;
    cout << "==========================" << endl;

    cout << "입력 >> ";
    cin >> userAgeInput;

    playerList[playerIndex]->SetUserInfo(userNameInput, userAgeInput);

    std::system("cls");
    playerList[playerIndex]->PrintUserInfo();

    cout << "[ 확인: Enter ]" << endl;
    cin.get();
    cin.get();

    return;
}
void SetCharInfo(vector<Player*>& playerList, int playerIndex)
{
    string userInput;

    std::system("cls");
    cout << "==========================" << endl;
    cout << "[ 닉네임을 입력하세요. ]" << endl;
    cout << "==========================" << endl;

    cout << "입력 >> ";
    cin >> userInput;
    playerList[playerIndex]->SetName(userInput);

    std::system("cls");
    cout << "==========================" << endl;
    cout << "[ 캐릭터 세팅 완료 ]" << endl;
    cout << "==========================" << endl;
    playerList[playerIndex]->PrintInfo();

    cout << "[ 회복 물약 1개가 지급되었습니다. ]" << endl;
    playerList[playerIndex]->AddItem("회복 물약");

    cout << "[ 확인: Enter ]" << endl;
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
void InventoryUseMenu(Player* player)
{
    int sel = 0;

    while (true)
    {
        std::system("cls");
        cout << "==========================" << endl;
        cout << "[ 아이템 목록 ]" << endl;
        player->PrintInventory();
        cout << "[ 9. 돌아가기 ]" << endl;
        cout << "==========================" << endl;

        cout << "선택 >> ";
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
            cout << "[ 확인: Enter ]" << endl;
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
        cout << "[ 인벤토리 ]" << endl;
        cout << "==========================" << endl;
        cout << "[ 1. 아이템 목록 ]" << endl;
        cout << "[ 2. 아이템 사용 ]" << endl;
        cout << "[ 0. 돌아가기 ]" << endl;
        cout << "==========================" << endl;
        cout << "선택 >> ";
        cin >> userInventorySel;

        switch (userInventorySel)
        {
        case 1:
            player->PrintInventory();
            cout << "[ 확인: Enter ]" << endl;
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
        cout << "[ 판매 목록 ]" << endl;
        shop->PrintShopList();
        cout << "[ 9. 돌아가기 ]" << endl;
        cout << "==========================" << endl;
        
        cout << "선택 >> ";
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
            cout << "[ 확인: Enter ]" << endl;
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
        cout << "[ 상점 ]" << endl;
        cout << "[ 1. 아이템 구매 ]" << endl;
        cout << "[ 2. 아이템 판매(미구현) ]" << endl;
        cout << "[ 0. 돌아가기 ]" << endl;
        cout << "==========================" << endl;
        cout << "선택 >> ";
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
        cout << "[ 마을 ]" << endl;
        cout << "==========================" << endl;
        cout << "[ 1. 인벤토리 ]" << endl;
        cout << "[ 2. 상점으로 ]" << endl;
        cout << "[ 0. 돌아가기 ]" << endl;
        cout << "==========================" << endl;
        cout << "선택 >> ";
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
        cout << "[ 전투 ]" << endl;
        cout << "==========================" << endl;
        cout << "[ 1. 일반 공격 ]" << endl;
        cout << "[ 2. 스킬 1 ]" << endl;
        cout << "[ 3. 스킬 2 ]" << endl;
        cout << "[ 4. 스킬 3 ]" << endl;
        cout << "[ 0. 마을로 ]" << endl;
        cout << "==========================" << endl;

        cout << "입력 >> ";
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
                cout << "[ 전투 종료 : 승리]" << endl;
                cout << "[ 확인: Enter ]" << endl;
                cin.get();
                cin.get();
                return;
            }
            cout << "[ " << monster->GetName() << " HP : " << monster->GetHp() << " ]" << endl;

            monster->Attack(player);
            if (!player->GetAlive())
            {
                cout << "[ 전투 종료 : 패배] " << endl;
                cout << "[ 확인: Enter ]" << endl;
                cin.get();
                cin.get();
                return;
            }
            cout << "[ " << player->GetName() << " HP : " << player->GetHp() << " ]" << endl;

            cout << "[ 확인: Enter ]" << endl;
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
        monster = new Monster("킹 슬라임");
        system("cls");
        std::cout << "==========================" << std::endl;
        std::cout << "Chapter " << *_progress << std::endl;
        std::cout << "[킹 슬라임 사냥]" << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << "거대한 슬라임이 쳐들어왔다 ㅜㅜ" << std::endl;

        cin.get();
        CombatMenu(player, monster);

        if (monster->GetAlive() == false
            && player->GetAlive() == true)
        {
            delete(monster);
            std::cout << "==========================" << std::endl;
            std::cout << "Chapter " << *_progress << std::endl;
            std::cout << "[킹 슬라임 사냥] 클리어" << std::endl;
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