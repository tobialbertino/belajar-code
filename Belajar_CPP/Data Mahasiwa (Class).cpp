#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#define SIZE 100
using namespace std;

class MHS
{
    // data members
    private:
        string nim;
        int usia, jenkel;
        float ipk;

    // member functions
    public:
        void setMHS(string n, int u, int j, float i)
        {
            nim = n; usia = u; jenkel = j; ipk = i;
        }
        void setNim(string n) { nim=n; }
        void setUsia(int u) { usia=u; }
        void setJenkel(int j) { jenkel=j; }
        void setIPK(float i) { ipk=i; }
		
        string getNim(){return nim;}
        int getUsia() { return usia; }
        int getJenkel() { return jenkel; }
        float getIPK() { return ipk; }
};

void tukar(MHS *a, MHS *b)
{
    MHS t = *a;
    *a = *b;
    *b = t;
}

void printclass(MHS no[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << no[i].getNim() <<" "<< no[i].getUsia() <<" "
             << no[i].getJenkel() <<" "<< fixed 
             << setprecision(2) << no[i].getIPK() << endl;
    }
}
int main()
{
    string nim;
    int usia, jenkel;
    float ipk;
    int i,n,nTukar,a,b;
    cin >> n;
    MHS no[n]; // declare tipe data MHS sebanyak n
    for(i = 0; i < n; i++)
    {
        cin >> nim >> usia >> jenkel >> ipk;
		no[i].setMHS(nim, usia, jenkel, ipk);
    }
    cin >> nTukar;
    for (i = 0; i < nTukar; i++)
    {
        cin >> a >> b;
        tukar(&no[a-1], &no[b-1]);
    }
    printclass(no, n);
     return 0;
}
