#include <iostream>
#include <new>
using namespace std;

class Base
{
	public:
        virtual void show() { cout<<"Base"; }
};

class Derived: public Base
{
    public:
        void show(){ cout<<"Derived"; }
};

int main(){
    Base* bp = new Derived;
    bp->show();
    return 0;
}

