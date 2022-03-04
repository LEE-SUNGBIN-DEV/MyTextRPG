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

// Combat Menu
void CombatMenu(Player* player, Monster* monster)
{
    int combatSel = 0;

    system("cls");
    cout << "==========================" << endl;
    cout << " 전투 메뉴" << endl;
    cout << "==========================" << endl;
    cout << " 1. 일반 공격" << endl;
    cout << " 2. 스킬 1" << endl;
    cout << " 3. 스킬 2" << endl;
    cout << " 4. 스킬 3" << endl;
    cout << " 0. 끝내기" << endl;
    cout << "==========================" << endl;

    while (true)
    {
        if (monster->GetHp < 0)
        {
            cout << "전투 종료" << endl;
            return;
        }

        cout << "입력 >> ";
        cin >> combatSel;
        switch (combatSel)
        {
        case 1:
            player->Attack(monster);
            cout << "몬스터 HP : " << monster->GetHp() << endl;
            break;
        case 2:
            player->SkillA(monster);
            cout << "몬스터 HP : " << monster->GetHp() << endl;
            break;
        case 3:
            player->SkillB(monster);
            break;
        case 4:
            player->SkillC(monster);
            break;
        case 0: return;
        }
    }
}

// Scene
void ChapterOne(Player* player, int _progress)
{ 
    Monster* monster = NULL;

    if (_progress == 0)
    {
        monster = new Monster("슬라임");
        system("cls");
        std::cout << "==========================" << std::endl;
        std::cout << "Chapter 1" << std::endl;
        std::cout << "[슬라임 사냥]" << std::endl;
        std::cout << "==========================" << std::endl;

        cin.get();
        CombatMenu(player, monster);
    }

    else
    {
        std::cout << "ERROR: WRONG ACCESS: MAIN STREAM CHAPTER 1" << std::endl;
        return;
    }
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
    int sel = 0;
    int progress = 0;

    sel = MainTitle();

    switch (sel)
    {
    case 1:
        CreatePlayer(playerList, player);
        SetUserInfo(playerList, 0);
        SetCharInfo(playerList, 0);

        ChapterOne(playerList[0], progress);

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