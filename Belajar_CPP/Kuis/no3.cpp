#include <iostream>
#include <string>
using namespace std;

class Buku
{
    public:
        buku () {}
        Buku (string s) : judul(s) {}
        void display() { cout<<judul<<endl; }
    private:
        string judul;
}

int main ()
{
    Buku b = new Buku("pemograman objek");
    b->display();
    return 0;
}