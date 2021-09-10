#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Akun{
    private:
        vector<int> list;

    public:
        Akun() { list.clear(); } 

        void setAllData(){
            int nilai;
            cin >> nilai;    
            list.push_back(nilai);
        }
        int getSize() { return list.size(); }

    
};

int main(){
    Akun akun;
    int n,t,i,j;

    cin >> t;
    for ( i = 0; i < t; i++)
    {
        cin >> n;
        for ( j = 0; j < n; i++)
        {
            akun.setAllData();
            
        }
        
    }
    


    return 0;
}