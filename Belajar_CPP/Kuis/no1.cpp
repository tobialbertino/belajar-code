#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main(){
    vector<int> v1;
    vector<int> v2;
    vector<int> vTotal;

    for (int i = 0; i < 3; ++i)
    {
        v1.push_back(( i + 2 ) * 3 % 5);
        v2.push_back(( 2 * i + 1 ) / 3);
    }

    v1.insert( v1.end(), v2.begin(), v2.end() );

    vector<int>::iterator iter;
    for (iter = v1.begin(); iter != v1.end(); iter++)
    {
        cout << *iter;
    }
    
    
}