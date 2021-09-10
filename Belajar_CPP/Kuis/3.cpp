#include <iostream>
using namespace std;

class Kotak{
    private:
        int panjang, lebar, tinggi;
        int volume() {return panjang*lebar*tinggi;}
    public:
        Kotak(int p=0, int l=0, int t=0){
            panjang=p;
            lebar=l;
            tinggi=t;
            cout<<volume();
        }
        void setPanjang(int p) {panjang=p; cout<<volume();}
        void setLebar(int l) {lebar=l; cout<<volume();}
        void setTinggi(int t) {tinggi=t; cout<<volume();}
        int getVolume() {return volume();}
};

int main(){
    Kotak kotak1(2,5,4);
    Kotak kotak2 = kotak1;
    kotak1.setLebar(3);
    cout << kotak1.getVolume() << kotak2.getVolume();
    return 0;
}

