#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Counter{
    private:
        int bil;
    
    public:
        void set(){
            int a;
            cin >> a;
                //if ( a<0 ) { a=0; }
            this->bil = a; 
        }
        void inc (){ this->bil += 1; }
        void dec (){
            if (this->bil-1 >= 0) { this->bil -=1; } 
        }
        void print(){
            cout << this->bil << endl;
        }

};

int main(){
    Counter counter;
    int n;
    int a;
    cin >> n;
    while (n != -9 ){
        if (n == 0 ){ counter.set(); }
        else if (n == 1) { counter.inc(); }
        else if (n == -1) { counter.dec(); }
        else if (n == 9) { counter.print(); }
        else {a=n;}
        cin >> n;
    }
}
