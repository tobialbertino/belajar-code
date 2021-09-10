#include<iostream>
#include<string>

// eksternal definition
#include "player.h"

using namespace std;

int main() {
    Player* playerObject = new Player("Saitama");
    playerObject->display();

    cout << "get name: " << playerObject->getName() << endl;

    cout << "ubah nama" << endl;
    playerObject->setName("Tanjiro");
    playerObject->display();

    return 0;
}

