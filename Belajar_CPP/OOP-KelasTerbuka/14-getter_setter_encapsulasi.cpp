#include <iostream>
#include <string>

using namespace std;

class Player{
    private:
        string name;
        double attackPower;
        int level;
        int exp;
    
    public:
        Player(const char* name){
            this->name = name;
            this->level = 1;
            this->exp = 0;
            this->attackPower = 100;
        }

        //getter, Ini artinya membuat attribute menjadi read only
        string getName();

        // setter, ini untuk Write data ke class
        void addExperience(int);
        void setName(const char*);
        void display();
};

 //getter, Ini artinya membuat attribute menjadi read only
string Player::getName(){
    return this->name;
}

// setter, ini untuk Write data ke class
void Player::addExperience(int expValue){
    int maxExp = 100;
    cout << "Mendapatkan exp = " << expValue << endl;
    this->exp += expValue;
    if (this->exp >= maxExp){
        // maka dia level up
        this->level++;
        this->attackPower +=100;
        cout << "LEVEL UP" << endl;
        this->exp = 0;
    }
}
void Player::setName(const char* name){
    this->name = name;
}
void Player::display(){
    cout << "Name\t: " << this->name << endl;
    cout << "Level :" << this->level << ", Exp : " << this->exp << endl;
    cout << "Attack\t: " << this->attackPower << endl;
}        

int main(){
    Player player1 = Player("Naruto"); // ini object di stack
    player1.display();

    // implementasi dari getter
    cout << player1.getName() << endl;;
    // player1.name = "Luna"; // tidak bisa write

    // kegiatan bertarung
    cout << "bertarung" << endl;
    player1.addExperience(25); // setter
    player1.display();
    player1.addExperience(50);
    player1.display();
    player1.addExperience(10);
    player1.display();
    player1.addExperience(25);
    player1.display();

    return 0;
}