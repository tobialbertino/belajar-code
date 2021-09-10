#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct mhs
{
    string nim;
    int usia, jenkel;
    float ipk;
};
typedef struct mhs MHS;
class myMhs
{
    private:
        MHS list[100];
        int n;
    public:
        void getAllData();        // Memasukkan data
        void printAllData() {     // Mencetak data
            cout.precision(2);
            for(int i=0; i<n; i++) {
                cout << list[i].nim << " " << list[i].usia << " "
                     << list[i].jenkel << " " << fixed << list[i].ipk << endl;
            }
        }
        void swap(int a, int b);  // Menukar posisi data
};

int main()
{
    myMhs obj;
    obj.getAllData();         // Membaca data mahasiswa

    int q, a, b;              // Baca dan proses tukar posisi data
    cin >> q;
    for (int i=0; i<q; i++)
    {
        cin >> a >> b;
        obj.swap(a-1, b-1);
    }

    obj.printAllData();       // Cetak data
    return 0;
}

// Implementasi fungsi membaca data mahasiswa
void myMhs::getAllData() 
{
    int kasus;
    cin >> kasus;
    n = kasus;      // mengisi data n
    string p_nim;
    int p_usia, p_jenkel;
    float p_ipk;
    for (int i=0; i<kasus; i++)
    {
    	cin >> p_nim >> p_usia >> p_jenkel >> p_ipk;
    	list[i].nim = p_nim;
    	list[i].usia = p_usia;
    	list[i].jenkel = p_jenkel;
    	list[i].ipk = p_ipk;
    }
}

// Implementasi fungsi menukar posisi data
void myMhs::swap(int a, int b)
{
    MHS t = list[a];
    list[a] = list[b];
    list[b] = t;
}