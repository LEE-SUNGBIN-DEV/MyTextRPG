#include <iostream>
#include <string>

#include "Character.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

#define MAX_SIZE 3

// �г��� Ž���ؼ� ��ġ�ϴ� �г��� ����� �ش� "�ε���" ��ȯ
int FindNicknameIndex(Player player[], string nick);

// �г��� Ž���ؼ� ��ġ�ϴ� �г��� ����� �÷��̾� ���� "���"
void PrintSearchPlayer(Player player[], int index);

// --------------------------------- Main
int main()
{
    Player player[MAX_SIZE];
    Monster monster[MAX_SIZE];

    player[0].SetName("player1");
    player[1].SetName("player2");
    player[2].SetName("player3");
    monster[0].SetName("����");
    monster[1].SetName("����");
    monster[2].SetName("�ܹ�");

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

// �г��� Ž���ؼ� ��ġ�ϴ� �г��� ����� �ش� "�ε���" ��ȯ
int FindNicknameIndex(Player player[], string nick)
{
    cout << "-------------------------------------" << endl;
    cout << "�г���: " << nick << "��(��) Ž���մϴ�." << endl;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (nick == player[i].name)
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
void PrintSearchPlayer(Player player[], int index)
{
    if (index == -1)
    {
        return;
    }

    else
    {
        cout << "�ش� �÷��̾��� ����" << endl;
        player[index].PrintInfo();
    }
}