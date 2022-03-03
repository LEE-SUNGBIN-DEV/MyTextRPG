#include <iostream>
#include <string>

#include "Character.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

#define MAX_SIZE 3

// 닉네임 탐색해서 일치하는 닉네임 존재시 해당 "인덱스" 반환
int FindNicknameIndex(Player player[], string nick);

// 닉네임 탐색해서 일치하는 닉네임 존재시 플레이어 정보 "출력"
void PrintSearchPlayer(Player player[], int index);

// --------------------------------- Main
int main()
{
    Player player[MAX_SIZE];
    Monster monster[MAX_SIZE];

    player[0].SetName("player1");
    player[1].SetName("player2");
    player[2].SetName("player3");
    monster[0].SetName("버섯");
    monster[1].SetName("개미");
    monster[2].SetName("꿀벌");

    player[0].PrintInfo();
    player[1].PrintInfo();
    player[2].PrintInfo();
    monster[0].PrintInfo();
    monster[1].PrintInfo();
    monster[2].PrintInfo();

    FindNicknameIndex(player, "1");
    FindNicknameIndex(player, "player3");

    PrintSearchPlayer(player, FindNicknameIndex(player, "1"));
    PrintSearchPlayer(player, FindNicknameIndex(player, "player3"));

    return 0;
}

// 닉네임 탐색해서 일치하는 닉네임 존재시 해당 "인덱스" 반환
int FindNicknameIndex(Player player[], string nick)
{
    cout << "-------------------------------------" << endl;
    cout << "닉네임: " << nick << "을(를) 탐색합니다." << endl;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (nick == player[i].name)
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