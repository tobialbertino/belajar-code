
#ifndef __PLAYER
#define __PLAYER 
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

#endif