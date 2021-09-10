#include <iostream>
#include <string>
using namespace std;

class Weapon{
    private:
        string name;
        double attackPower;

    public:
        Weapon(const char*, double);
        void display();
        string getName();
};

class Player{
    private:
        string name;
        Weapon* weapon;
    
    public:
        Player(const char*);
        void display();
        //setter
        void equipWeapon(Weapon*);
};

// Player_________________________________________________________________________________

// Penjabaran fungsi
Player::Player(const char* name){
    this->name = name;
}
void Player::display(){
    cout << "Player ini adalah " << this->name << endl;
    cout << "Menggunakan senjata: " << this->weapon->getName();
}
void Player::equipWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

// Weapon_________________________________________________________________________________
Weapon::Weapon(const char* name, double attackPower){
    this->name = name;
    this->attackPower = attackPower;
}
void Weapon::display(){
    cout << "Weapon ini adalah " << this->name;
    cout << " power = " << this->attackPower << endl;
}
string Weapon::getName(){
    return this->name;
}


int main(){
    Player* player1 = new Player("Sniper");
    Weapon* weapon1 = new Weapon("Senapan", 50);

    //implementasi setter untuk meng equip weapon
    player1->equipWeapon(weapon1);

    player1->display();
    return 0;
}