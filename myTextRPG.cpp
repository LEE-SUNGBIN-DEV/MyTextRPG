#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

#include "MainStream.h"
#include "Character.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

#define MAX_SIZE 100
string gameTitle = "TEXT RPG";

// 몬스터 타입 목록
enum MyMonsterType
{
    ENUM_MONSTER_SLIME,
    ENUM_MONSTER_GOBLIN,
    ENUM_MONSTER_DRAGON
};

// 속성 목록
enum MyElementType
{
    ENUM_ELEMENT_FIRE,
    ENUM_ELEMENT_WATER,
    ENUM_ELEMENT_WIND,
    ENUM_ELEMENT_LAND,
    ENUM_ELEMENT_LIGHT,
    ENUM_ELEMENT_DARK
};

int MainTitle()
{
    int titleSel;

    system("cls");
    cout << "==========================" << endl;
    cout << gameTitle << endl;
    cout << "==========================" << endl;
    cout << "1. 게임 시작" << endl;
    cout << "2. 게임 종료" << endl;
    cout << "선택 >> ";

    cin >> titleSel;

    return titleSel;
}
void SetPlayer(vector<Character*>& playerList, Character*& player)
{
    int playerSel;

    system("cls");
    cout << "==========================" << endl;
    cout << "직업을 선택하세요." << endl;
    cout << "1. 전사" << endl;
    cout << "2. 마법사" << endl;
    cout << "==========================" << endl;
    cout << "선택 >> ";
    cin >> playerSel;

    while (true)
    {
        if (playerSel == ENUM_PLAYER_KNIGHT
            || playerSel == ENUM_PLAYER_MAGICIAN)
        {
            player = new Player(playerSel);
            playerList.push_back(player);
            cout << "직업 선택 완료" << endl;

            return;
        }

        else
        {
            cout << "ERROR: WRONG INPUT: setPlayer()" << endl;
        }
    }
}

void CreateMonster(vector<Character*>& monsterList, Character*& monster)
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

// 닉네임 탐색해서 일치하는 닉네임 존재시 해당 "인덱스" 반환
int FindNicknameIndex(Player player[], string nick);
// 닉네임 탐색해서 일치하는 닉네임 존재시 플레이어 정보 "출력"
void PrintSearchPlayer(Player player[], int index);

// --------------------------------- Main
int main()
{
    MainStream* Scene;
    Character* player = NULL;
    Character* monster = NULL;
    vector<Character*> playerList;
    vector<Character*> monsterList;
    int sel = 0;

    Scene = new MainStream();

    sel = MainTitle();
    switch (sel)
    {
    case 1:
        SetPlayer(playerList, player);

    case 2: return 0;
    }
    
    return 0;
}

// 닉네임 탐색해서 일치하는 닉네임 존재시 해당 "인덱스" 반환
int FindNicknameIndex(Player player[], string nick)
{
    cout << "-------------------------------------" << endl;
    cout << "닉네임: " << nick << "을(를) 탐색합니다." << endl;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (nick == player[i].GetName())
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
void PrintSearchPlayer(Player player[], int index)
{
    if (index == -1)
        return;

    else
    {
        cout << "해당 플레이어의 정보" << endl;
        player[index].PrintInfo();
    }
}