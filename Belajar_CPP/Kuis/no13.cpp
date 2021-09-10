#include <iostream>

class What{
    protected:
    int x;
};
int main(){
    What t;
    std::cout << t.x;
    return 0;
}