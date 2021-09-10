#include <iostream>
#include <string>

using namespace std;

class Mahasiswa{
    // attribute
    private: // hanya dapat diakses oleh class itu sendiri
        string namePrivate;

    public: // ini dapat diakses oleh siapa pun
        string namePublic;

    // method dan constructor
    // public:   
        // constructor selalu public
        Mahasiswa(const char*);

        void showDisplay();
    private:
        void showDisplayPrivate();
};


Mahasiswa::Mahasiswa(const char* name){
    this->namePublic = name;
    this->namePrivate = name;
}

void Mahasiswa::showDisplay(){
    cout << "Nama Mahasiswa : " << this->namePrivate << endl;
}

void Mahasiswa::showDisplayPrivate(){
    cout << "Nama Mahasiswa : " << this->namePrivate << endl;
}

int main(){
    Mahasiswa* mahasiswa1 = new Mahasiswa("Ucup");
    // kita akan akses data public dan private
    cout << mahasiswa1->namePublic << endl; // karena public dapat di akses
    // cout << mahasiswa1->namePrivate << endl; // Private tidak dapat diakses

    Mahasiswa* mahasiswa2 = new Mahasiswa("Marisa");
    mahasiswa2->showDisplay(); // dapat dilakukan karena method public
    // mahasiswa2->showDisplayPrivate(); // tidak bisa karena private

    Mahasiswa* mahasiswaRantau = new Mahasiswa("John");
    mahasiswaRantau->showDisplay();

    return 0;
}
