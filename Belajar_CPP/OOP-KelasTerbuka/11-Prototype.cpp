#include<iostream>
#include<string>

using namespace std;

// Deklarasi class

class Player{
    public:
        string name;

        // Constructor 
        Player(const char*); //{this->name = name;} dalam bentuk prototype
        void display();
        string getName();
        void setName(const char*);
};


int main() {
    Player* playerObject = new Player("Marni");
    playerObject->display();

    cout << "get name: " << playerObject->getName() << endl;

    cout << "ubah nama" << endl;
    playerObject->setName("Isabella");
    playerObject->display();

    return 0;
}

// Penjabaran Method
Player::Player(const char* name){
    // Player::name = name;
    this->name = name;
}
void Player::display(){
    cout << "Nama Player: " << this->name << endl;
}

string Player::getName(){
    return this->name;
}

void Player::setName(const char* name){
    this->name = name;
}