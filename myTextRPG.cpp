#include <iostream>
#include <string>
#include <vector>

#include "Character.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

#define MAX_SIZE 100

// 직업 목록
enum MyPlayerType
{

};

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

// 닉네임 탐색해서 일치하는 닉네임 존재시 해당 "인덱스" 반환
int FindNicknameIndex(Player player[], string nick);

// 닉네임 탐색해서 일치하는 닉네임 존재시 플레이어 정보 "출력"
void PrintSearchPlayer(Player player[], int index);

void CreateMonster(vector<Character*>& monsterList, Character*& monster)
{
    string monSel;

    while (true)
    {
        cout << "----------------------------------------------------" << endl;
        cout << "(몬스터 생성) 목록: 슬라임, 고블린, 드래곤 / (X) 종료" << endl;
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
            cout << "Unknown Moster Type" << endl;
        }
    }
}

// --------------------------------- Main
int main()
{
    vector<Character*> monsterList;
    Character* monster = NULL;

    //---------------------------------------몬스터 생성 시작
    CreateMonster(monsterList, monster);
    //---------------------------------------몬스터 생성 끝

    for (int i = 0; i < monsterList.size(); i++)
    {
        monsterList[i]->PrintInfo();
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
    {
        return;
    }

    else
    {
        cout << "해당 플레이어의 정보" << endl;
        player[index].PrintInfo();
    }
}