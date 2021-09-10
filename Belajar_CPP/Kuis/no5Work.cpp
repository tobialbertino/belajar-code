#include <iostream>
using namespace std;

class Work {
    private:
        int waktu;
        int upah;
    
    public:
        Work (int a, int b){ waktu = a, upah = b; }
        Work (int b){ upah = b; }
        void add(int);
        void printUpah();
        reset(Work) { waktu=0; }
        int subtract(int);

};

void Work::add(int a){
    this->waktu = this->waktu + a;
}
void Work::printUpah(){
    cout << this->waktu * this->upah << " rupiah" << endl;

}
int Work::subtract(int a){
    if (a <= this->waktu){
        return this->waktu = this->waktu -= a;
    }
}

int main(){
    Work* w = new Work(25, 60);
    w->add(65);
    w->printUpah();
    Work::reset(w);
    bool res = w->subtract(60);
    Work* v = new Work(30);
    return 0;
}

