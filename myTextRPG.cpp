#include <iostream>
#include <string>
using namespace std;

const int maxSize = 3;

struct UserInfo
{
    string userName;
    int userAge;
};

// --------------------------------- CLASS
// --------------------------------- CHARACTER
struct Character
{
    string name;
    int hp;
    int mp;
    float moveSpeed;
    bool alive;

    // 생성자
    Character()
    {
        this->name = "NONE";
        this->hp = 100;
        this->mp = 50;
        this->moveSpeed = 1.0f;
        this->alive = true;
    }

    // 기능 함수
    void rebirth()
    {
        this->alive = true;
        cout << "부활하였습니다" << endl;
    }

    void death()
    {
        this->alive = false;
        cout << "사망하였습니다" << endl;
    }

    // 캐릭터 정보 출력
    void PrintInfo()
    {
        cout << "-------------------------------------" << endl;
        cout << "   Name: " << this->name << endl;
        cout << "   HP: " << this->hp << endl;
        cout << "   MP: " << this->mp << endl;
        cout << "   이동속도: " << this->moveSpeed << endl;
        if (this->alive == true)
            cout << "   상태: 생존" << endl;
        else if (this->alive == false)
            cout << "   상태: 사망" << endl;
        cout << "-------------------------------------" << endl;

        return;
    }

    // Get Info
    string GetName() { return this->name; }
    int GetHp() { return this->hp; }
    int GetMp() { return this->mp; }
    float GetMoveSpeed() { return this->moveSpeed; }
    bool GetAlive() { return this->alive; }

    // Set Info
    void SetName(string _name)
    {
        this->name = _name;
        return;
    }
    void SetHp(int _hp)
    {
        this->hp = _hp;
        return;
    }
    void SetMp(int _hp)
    {
        this->hp = _hp;
        return;
    }
    void SetMoveSpeed(float _moveSpeed)
    {
        this->moveSpeed = _moveSpeed;
    }
};

// --------------------------------- CLASS
// --------------------------------- PLAYER
struct Player :Character
{
    UserInfo userInfo;
    int dmg;
    int exp;

    // 생성자
    Player()
    {
        this->dmg = 2.0f;
        this->exp = 0;
        this->userInfo.userAge = 0;
        this->userInfo.userName = "NONE";
    }

    // 기능 함수
    void PrintInfo()
    {
        cout << "-------------------------------------" << endl;
        cout << "   Name: " << this->name << endl;
        cout << "   HP: " << this->hp << endl;
        cout << "   MP: " << this->mp << endl;
        cout << "   DMG: " << this->dmg << endl;
        cout << "   이동속도: " << this->moveSpeed << endl;
        if (this->alive == true)
            cout << "   상태: 생존" << endl;
        else if (this->alive == false)
            cout << "   상태: 사망" << endl;
        cout << "   exp: " << this->exp << endl;
        cout << "   userAge: " << this->userInfo.userAge << endl;
        cout << "-------------------------------------" << endl;

        return;
    }

    // Get Info
    UserInfo GetUserInfo() { return this->userInfo; }
    int GetDmg() { return this->dmg; }
    int GetExp() { return this->exp; }

    // Set Info
    void SetUserInfo(string _name, int _age)
    {
        this->userInfo.userName = _name;
        this->userInfo.userAge = _age;
    }
    void SetDmg(int _dmg)
    {
        this->dmg = _dmg;
        return;
    }
    void SetExp(int _exp)
    {
        this->exp = _exp;
        return;
    }
};

// --------------------------------- CLASS
// --------------------------------- MONSTER
struct Monster :Character
{
    string element;
    int dmg;

    // 생성자
    Monster()
    {
        this->element = "NONE";
        this->name = "NONE";
        this->dmg = 1.0f;
    }

    // 기능 함수
    void PrintInfo()
    {
        cout << "-------------------------------------" << endl;
        cout << "   Name: " << this->name << endl;
        cout << "   HP: " << this->hp << endl;
        cout << "   MP: " << this->mp << endl;
        cout << "   DMG: " << this->dmg << endl;
        cout << "   이동속도: " << this->moveSpeed << endl;
        if (this->alive == true)
            cout << "   상태: 생존" << endl;
        else if (this->alive == false)
            cout << "   상태: 사망" << endl;
        cout << "   속성: " << this->element << endl;
        cout << "-------------------------------------" << endl;

        return;
    }

    // Get Info
    string GetElement() { return this->element; }
    int GetDmg() { return this->dmg; }

    // Set Info
    void SetElement(string _element)
    {
        this->element = _element;
        return;
    }
    void SetDmg(int _dmg)
    {
        this->dmg = _dmg;
        return;
    }
};

// 외부 함수
// 닉네임 탐색해서 일치하는 닉네임 존재시 해당 "인덱스" 반환
int FindNicknameIndex(Player player[], string nick);
// 닉네임 탐색해서 일치하는 닉네임 존재시 플레이어 정보 "출력"
void PrintSearchPlayer(Player player[], int index);

// --------------------------------- Main
int main()
{
    Player player[maxSize];
    Monster monster[maxSize];

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

    for (int i = 0; i < maxSize; i++)
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