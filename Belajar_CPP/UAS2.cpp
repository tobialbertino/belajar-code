#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Pegawai
{
    protected:
        string id;
        int usia, tipe;
        int income;
    public:
        void set(string pid, int u, int t ) {id=pid; usia=u; tipe=t; }
        string getID() { return id; }
        void print() { cout << id << " " << tipe << " " << income << endl; }
};

int main()
{
    vector<Tetap> pt;
    vector<Harian> ph;
    int n, u, t;
    string pid;
    Pegawai pegawai
    cin >> n;
    for ( i = 0; i < n; i++)
    {
        cin >> pid >> u >> t >>
    }
    


    return 0;
}