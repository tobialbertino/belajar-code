#include <iostream>
using namespace std;

class  MyClass {
    public:
        MyClass() {cout <<'*';}
};

int main(){
    MyClass* p1= new MyClass[5];
    cout << '\n';
    delete[] p1;
    
    return 0;
}

