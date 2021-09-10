#include <iostream>
#include <iomanip>
using namespace std;
class Orang
{
    protected:
        string nama;
        string id;
        int usia;
    public:
        Orang() { nama=id=""; usia=0; }
        void setOrang(string nm, string pid, int u) {
            nama=nm; id=pid; usia=u;
        }
        void print() { cout << nama << " " << id << " " << usia << endl; }
        string getNama() { return nama; }
        string getID() { return id; }
        int getUsia() { return usia; }
};
class Mahasiswa:public Orang
{
    protected:
        string nim;
        float ipk;
    public:
        Mahasiswa() { Orang(); nim=""; ipk=0.0; }
        void setMhs(string nm, string pid, int u, string pnim, float pipk) {
            setOrang(nm,pid,u);
            nim=pnim; ipk=pipk;
        }
        void print() {
            cout.precision(2);
            cout << nama << " " << id << " " << usia << " " << nim << " " << fixed << ipk << endl;
        }
};
int main()
{
    Mahasiswa m;
    m.setMhs("Abdullah","3219629876232",21,"G64212521", 3.45);
    m.print();
    return 0;
}