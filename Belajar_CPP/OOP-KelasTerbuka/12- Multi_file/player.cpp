
#include "player.h"

// Penjabaran Method
Player::Player(const char* name){
    // Player::name = name;
    this->name = name;
}
void Player::display(){
    cout << "Nama Player: " << this->name << endl;
    cout << "Class ini berada di file terpisah" << endl;
}

string Player::getName(){
    return this->name;
}

void Player::setName(const char* name){
    this->name = name;
}