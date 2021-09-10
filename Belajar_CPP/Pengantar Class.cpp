#include <iostream>
#include <string>
using namespace std;
class Orang
{
    // data members
    private:
        string nama;
        string id;
        int usia;
        bool jenkel;

    // member functions
    public:
        void setOrang(string n, string i, int u, bool j)
        {
            nama=n; id=i; usia=u; jenkel=j;
        }
        void setNama(string n) { nama=n; }
        void setID(string i) { id=i; }
        void setUsia(int u) { usia=u; }
        void setJenis(bool j) { jenkel=j; }

        string getNama() { return nama; }
        string getID() { return id; }
        int getUsia() { return usia; }
        string getJenis() { return (jenkel)?"Laki-laki":"Perempuan"; }
};
int main()
{
     Orang p1;
     p1.setOrang("Covid Corona", "3287192819", 19, true);

     cout << p1.getNama() << " " << p1.getID() << " "
          << p1.getUsia() << " " << p1.getJenis() << endl;

     return 0;
}