#include <iostream>
#include <string>
#include <vector>
#include <Windows.h> // system()

#include "Character.h"
#include "Monster.h"
#include "LUX.h"
#include "Yasuo.h"

#include "Player.h"
#include "Knight.h"
#include "Wizard.h"

#include "Shop.h"
#include "HpPotion.h"
#include "MpPotion.h"

using namespace std;

string gameTitle = "협곡의 쓰레기";

// global
Shop* shop = new Shop();

// Input Control
void GetCombatBuffer()
{
    cout << endl;
    cout << "▷ [ 혼내주자 : Enter ]" << endl;
    cin.get();
}
void GetOneBuffer()
{
    cout << endl;
    cout << "▷ [ 확인: Enter ]" << endl;
    cin.get();
}
void GetTwoBuffer()
{
    cout << endl;
    cout << "▷ [ 확인: Enter ]" << endl;
    cin.get();
    cin.get();
}

// init
int MainTitle()
{
    int userSel;
    
    while (true)
    {
        std::system("cls");
        cout << "============================" << endl;
        cout << "　[" << gameTitle << " ]" << endl;
        cout << "============================" << endl;
        cout << "[ 1. 게임 시작 ]" << endl;
        cout << "[ 2. 게임 종료 ]" << endl;
        cout << "선택 >> ";

        cin >> userSel;

        if (userSel == 1 || userSel == 2)
        {
            return userSel;
        }

        else
        {
            cout << "ERROR: WRONG INPUT: MainTitle()" << endl;
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
        cout << "====================================" << endl;
        cout << "[ 직업을 선택하세요. ]" << endl;
        cout << "[ 1. 전사 ]" << endl;
        cout << "[ 2. 마법사 ]" << endl;
        cout << "====================================" << endl;
        cout << "선택 >> ";

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
    cout << "====================================" << endl;
    cout << "[ 성함을 입력하세요. ]" << endl;
    cout << "====================================" << endl;

    cout << "입력 >> ";
    cin >> userNameInput;
    
    std::system("cls");
    cout << "====================================" << endl;
    cout << "[ 나이를 입력하세요. ]" << endl;
    cout << "====================================" << endl;

    cout << "입력 >> ";
    cin >> userAgeInput;

    playerList[playerIndex]->SetUserInfo(userNameInput, userAgeInput);

    std::system("cls");
    cout << "[ 유저 정보 ]" << endl;
    playerList[playerIndex]->PrintUserInfo();

    GetTwoBuffer();

    return;
}
void SetCharInfo(vector<Player*>& playerList, int playerIndex)
{
    string userInput;

    std::system("cls");
    cout << "====================================" << endl;
    cout << "[ 닉네임을 입력하세요. ]" << endl;
    cout << "====================================" << endl;

    cout << "입력 >> ";
    cin >> userInput;
    playerList[playerIndex]->SetName(userInput);

    std::system("cls");
    cout << "====================================" << endl;
    cout << "[ 캐릭터 세팅 완료 ]" << endl;
    cout << "====================================" << endl;
    playerList[playerIndex]->PrintInfo();
    cout << "====================================" << endl;
    cout << "[ 회복 물약 1개가 지급되었습니다. ]" << endl;
    cout << "[ 마나 물약 1개가 지급되었습니다. ]" << endl;
    playerList[playerIndex]->AddItem(new HpPotion(1));
    playerList[playerIndex]->AddItem(new MpPotion(1));

    GetTwoBuffer();

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
void InitShop()
{
    shop->GetSellList().push_back(new HpPotion(999));
    shop->GetSellList().push_back(new MpPotion(999));
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
    tryAgain:
        std::system("cls");
        cout << "===============================" << endl;
        cout << "[ 전투 ]" << endl;
        cout << "===============================" << endl;
        cout << "[ " << player->GetName() << "의 스테이터스 ]" << endl;
        cout << "[ HP: " << player->GetHp() << " / " << "MP: " << player->GetMp() << " / " << "보호막: " << player->GetShield() << " ]" << endl;
        cout << "[ 공격력: " << player->GetDmg() << " / " << "방어력: " << player->GetDef() << " ]" << endl;
        cout << "===============================" << endl;
        cout << "[ " << monster->GetName() << "의 스테이터스 ]" << endl;
        cout << "[ HP: " << monster->GetHp() << " / " << "보호막: " << monster->GetShield() << " ]" << endl;
        cout << "[ 공격력: " << monster->GetDmg() << " / " << "방어력: " << monster->GetDef() << " ]" << endl;
        cout << "===============================" << endl;
        cout << "[ 1. 일반 공격 ]" << endl;
        cout << "[ 2. 스킬 1 ]" << endl;
        cout << "[ 3. 스킬 2 ]" << endl;
        cout << "[ 4. 스킬 3 ]" << endl;
        cout << "[ 0. 마을로 ]" << endl;
        cout << "===============================" << endl;
        
        cout << "입력 >> ";
        cin >> sel;

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
            break;
        }

        if (sel != 0)
        {
            if (!monster->GetAlive())
            {
                cout << "[ 전투 종료 : 승리]" << endl;
                GetTwoBuffer();
                return;
            }

            monster->RandomAttack(player);
            if (!player->GetAlive())
            {
                cout << "[ 전투 종료 : 패배] " << endl;
                GetTwoBuffer();
                return;
            }

            GetTwoBuffer();
        }
    }
}

// Scene
void GameOver()
{
    system("cls");
    std::cout << "==========================" << std::endl;
    std::cout << " [ Game Over ] " << endl;
    std::cout << "==========================" << std::endl;
    cout << "[ 협곡을 지켜낼 수 없었다. ]" << endl;
    GetOneBuffer();

    return;
}
void Prologue()
{
    system("cls");
    std::cout << "==========================" << std::endl;
    std::cout << " [ Prologue ] " << endl;
    std::cout << "==========================" << std::endl;
    cout << "[ 소환사의 협곡에는 수많은 쓰레기가 존재한다. ]" << endl;
    cout << "[ 당신은 지금부터 그 쓰레기들을 청소해야 한다. ]" << endl;
    GetOneBuffer();
}
void Chapter1(Player* player, int* _progress)
{ 
    Monster* monster = NULL;

    while (*_progress == 1)
    {
        monster = new LUX();
        system("cls");
        std::cout << "==========================" << std::endl;
        std::cout << "Chapter " << *_progress << std::endl;
        std::cout << "[서폿 럭스]" << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << " \"원딜님 CS가 맛있네용ㅎ\" " << std::endl;

        GetCombatBuffer();
        CombatMenu(player, monster);

        if (monster->GetAlive() == false
            && player->GetAlive() == true)
        {
            delete(monster);
            system("cls");
            std::cout << "==========================" << std::endl;
            std::cout << "Chapter " << *_progress << std::endl;
            std::cout << "[서폿 럭스] 클리어" << std::endl;
            std::cout << "==========================" << std::endl;
            std::cout << " \"ㅇㄷㅊㅇ\" " << endl;
            
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
}
void Chapter3(Player* player, int* _progress)
{
}
void Epilogue()
{
    system("cls");
    std::cout << "==========================" << std::endl;
    std::cout << " [ Epilogue ] " << endl;
    std::cout << "==========================" << std::endl;
    cout << "[ 당신의 끈질긴 노력덕에 ]" << endl;
    cout << "[ 소환사의 협곡에 평화가 찾아왔다. ]" << endl;

    GetTwoBuffer();

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
        Epilogue();

    case 2:
        return 0;
    }

    delete(shop);
    
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