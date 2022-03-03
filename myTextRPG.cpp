#include <iostream>
#include <string>
#include <vector>

#include "Character.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

#define MAX_SIZE 100

// ���� ���
enum MyPlayerType
{

};

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

// �г��� Ž���ؼ� ��ġ�ϴ� �г��� ����� �ش� "�ε���" ��ȯ
int FindNicknameIndex(Player player[], string nick);

// �г��� Ž���ؼ� ��ġ�ϴ� �г��� ����� �÷��̾� ���� "���"
void PrintSearchPlayer(Player player[], int index);

void CreateMonster(vector<Character*>& monsterList, Character*& monster)
{
    string monSel;

    while (true)
    {
        cout << "----------------------------------------------------" << endl;
        cout << "(���� ����) ���: ������, ���, �巡�� / (X) ����" << endl;
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
            cout << "Unknown Moster Type" << endl;
        }
    }
}

// --------------------------------- Main
int main()
{
    vector<Character*> monsterList;
    Character* monster = NULL;

    //---------------------------------------���� ���� ����
    CreateMonster(monsterList, monster);
    //---------------------------------------���� ���� ��

    for (int i = 0; i < monsterList.size(); i++)
    {
        monsterList[i]->PrintInfo();
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
    {
        return;
    }

    else
    {
        cout << "�ش� �÷��̾��� ����" << endl;
        player[index].PrintInfo();
    }
}