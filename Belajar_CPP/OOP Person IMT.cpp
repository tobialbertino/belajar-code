#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#define SIZE 100

using namespace std;

class person
{
    // data members
    private:
        string nama;
        int usia;
        int tinggi;
        double berat;
    // member functions
    public:
        void setPerson(string n, int u, int t, double b)
        {
            nama = n; 
            usia = u; 
            tinggi = t; 
            berat = b;
        }
        void setNama(string n) { nama=n; }
        void setUsia(int u) { usia=u; }
        void setTinggi(int t) { tinggi=t; }
        void setBerat(double b) { berat=b; }
        
        string getNama(){return nama;}
        int getUsia() { return usia; }
        int getTinggi() { return tinggi; }
        double getBerat() { return berat; }

        int cekTinggi(double mean)
        {
            if (tinggi > mean) return 1;
            else return 0;
        }
        void cetakData()
        {
            cout << nama<<' '<< usia <<' '<< tinggi <<' '<< setprecision(2) << berat <<' '<< setprecision(2) << getIMT();
        }
        double getIMT()
        {
            double meter = tinggi*1.0/100;
            return berat/(meter*meter);
        }
        int getStatusGizi()
        {
            if(getIMT()>=28.0){ cout<<"sangat gemuk"; return 4; }
            else if(getIMT()>=25.0){ cout<<"gemuk"; return 3; }
            else if(getIMT()>=18.5){ cout<<"normal"; return 2; }
            else if(getIMT()>=17.0){ cout<<"kurus"; return 1; }
            else { cout<<"sangat kurus"; return 0; }
        }
};

void tukar(person *a, person *b)
{
    person t = *a;
    *a = *b;
    *b = t;
}

void printclass(person no[], int n)
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
    int usia, tinggi;
    double berat, mean;
    int i,n, total = 0, JA = 0;
    
    cin >> n;
    person no[n]; // declare tipe data MHS sebanyak n
    int status[5]={0};

    for(i = 0; i < n; i++)
    {
        cin >> nama >> usia >> tinggi >> berat;
        no[i].setPerson(nama, usia, tinggi, berat);
        total += tinggi;
    }
    mean = total*1.0 / n;
    for(i = 0; i < n; i++)
    {
        no[i].cetakData();
        cout <<" ";
        status[no[i].getStatusGizi()]++;
        cout << endl;
        JA += no[i].cekTinggi(mean);
    }
    cout<<fixed<<setprecision(2)<<mean<<endl;
    cout<<JA<<endl;
    cout<<status[0]<<" "<<status[1]<<" "<<status[2]<<" "<<status[3]<<" "<<status[4]<<endl;
    
   
     return 0;
}
