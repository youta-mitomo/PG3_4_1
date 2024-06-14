#include <iostream>
#include <conio.h> 
using namespace std;

class Enemy{
public:
    void Update();
    void approach();
    void shoot();
    void retreat();

    static void (Enemy::* table[])();

private:
    int index = 0;
};

void Enemy::approach(){
    cout << "敵の接近！" << endl;
}

void Enemy::shoot(){
    cout << "敵の攻撃！" << endl;
}

void Enemy::retreat(){
    cout << "敵の後退！" << endl;
}


void Enemy::Update(){
    (this->*table[index])();


    while (true){
        if (_kbhit()){
            char key = _getch();
            if (key == ' '){
                index = (index + 1) % 3; // 配列のインデックスを+1し、配列の最後に達したら0に戻す

                break;
            }
        }
    }
}

void (Enemy::* Enemy::table[])() ={
    &Enemy::approach,
    &Enemy::shoot,
    &Enemy::retreat
};

int main(){
    Enemy my;
    while (true){
        my.Update();
    }

    return 0;
}