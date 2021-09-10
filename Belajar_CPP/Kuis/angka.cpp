#include <iostream>
using namespace std;

class Angka{
    private:
        int x;
    public:
        Angka() { x=5; cout << x; }
        int getAngka() { return x; }
};

int main(){
    Angka angka = Angka();
    cout << angka.getAngka() << endl;
    return 0;
}
