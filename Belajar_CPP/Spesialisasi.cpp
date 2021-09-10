#include <iostream>

using namespace std;

class Segiempat
{
    protected:
        int panjang, lebar;
    public:
        Segiempat() { panjang=lebar=0; }
        void setNilai(int p, int l) { panjang=p; lebar=l; }
        int getLuas() { return panjang*lebar; }
};

class Bujursangkar: public Segiempat
{
    public:
        Bujursangkar() { Segiempat(); }
        void setNilai(int sisi) { panjang=lebar=sisi;}
};

int main()
{
    Bujursangkar obj;
    obj.setNilai(5);
    cout << obj.getLuas() << endl;
    return 0;
}