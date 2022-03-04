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

// ���� Ÿ�� ���
enum MyMonsterType
{
    ENUM_MONSTER_SLIME,
    ENUM_MONSTER_GOBLIN,
    ENUM_MONSTER_DRAGON
};

// �Ӽ� ���
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
    cout << "1. ���� ����" << endl;
    cout << "2. ���� ����" << endl;
    cout << "���� >> ";

    cin >> titleSel;

    return titleSel;
}
void SetPlayer(vector<Character*>& playerList, Character*& player)
{
    int playerSel;

    system("cls");
    cout << "==========================" << endl;
    cout << "������ �����ϼ���." << endl;
    cout << "1. ����" << endl;
    cout << "2. ������" << endl;
    cout << "==========================" << endl;
    cout << "���� >> ";
    cin >> playerSel;

    while (true)
    {
        if (playerSel == ENUM_PLAYER_KNIGHT
            || playerSel == ENUM_PLAYER_MAGICIAN)
        {
            player = new Player(playerSel);
            playerList.push_back(player);
            cout << "���� ���� �Ϸ�" << endl;

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
        cout << "(���� ����) ���: ������, ���, �巡�� / X: ����" << endl;
        cout << "----------------------------------------------------" << endl;
        cin >> monSel;
        if (monSel == "������" || monSel == "���" || monSel == "�巡��")
        {
            monster = new Monster(monSel);
            monsterList.push_back(monster);
            cout << monSel << " " << "���� �Ϸ�" << endl;
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

// �г��� Ž���ؼ� ��ġ�ϴ� �г��� ����� �ش� "�ε���" ��ȯ
int FindNicknameIndex(Player player[], string nick);
// �г��� Ž���ؼ� ��ġ�ϴ� �г��� ����� �÷��̾� ���� "���"
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

// �г��� Ž���ؼ� ��ġ�ϴ� �г��� ����� �ش� "�ε���" ��ȯ
int FindNicknameIndex(Player player[], string nick)
{
    cout << "-------------------------------------" << endl;
    cout << "�г���: " << nick << "��(��) Ž���մϴ�." << endl;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (nick == player[i].GetName())
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
        return;

    else
    {
        cout << "�ش� �÷��̾��� ����" << endl;
        player[index].PrintInfo();
    }
}