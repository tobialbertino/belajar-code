#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>

using namespace std;

class Person
{
    // data members
    public:
        string nama;
        int usia;
        int tinggi;
        double berat;
    // member functions
    public:
        void setPerson(string n, int u, int t, double b)
        {
            nama = n; usia = u; tinggi = t; berat = b;
        }
        void setNama(string n) { nama=n; }
        void setUsia(int u) { usia=u; }
        void setTinggi(int t) { tinggi=t; }
        void setBerat(double b) { berat=b; }
        
        string getNama(){return nama;}
        int getUsia() { return usia; }
        int getTinggi() { return tinggi; }
        double getBerat() { return berat; }

        int jumlah(int total, int t)
        {
            tinggi = t;
            total += tinggi;
            return total;
        }
};

void tukar(Person *a, Person *b)
{
    Person t = *a;
    *a = *b;
    *b = t;
}

void printclass(Person no[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << no[i].getNama() <<" "<< no[i].getUsia() <<endl;
             //<< no[i].getTinggi() <<" "<< fixed 
             //<< setprecision(2) << no[i].getBerat() << endl;
    }
}
int main()
{
    string nama;
    int usia, tinggi, total = 0;
    double berat, rata2Berat;
    int i,n,nTukar,a,b, JA;
    
    cin >> n;
    Person no[n]; // declare tipe data MHS sebanyak n

    for(i = 0; i < n; i++)
    {
        cin >> nama >> usia >> tinggi >> berat;
        no[i].setPerson(nama, usia, tinggi, berat);
        total += no[i].tinggi;
    }
    
    rata2Berat = total*1.0 / n;

    for(i = 0; i < n; i++)
    {
        if (no[i].tinggi > rata2Berat)
            JA += 1;
    }
    cout << fixed<< setprecision(2) << rata2Berat << endl;
    cout << JA << endl;


     return 0;
}
