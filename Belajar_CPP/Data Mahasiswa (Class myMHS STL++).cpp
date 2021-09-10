#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
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
        vector<MHS> list;
    public:
    	myMhs() { list.clear(); }
    	myMhs(int p, MHS pt[]) {
    	    for (int i=0; i<p; i++) 
                list.push_back(pt[i]);
    	}
        void getAllData();        // Memasukkan data
        void printAllData() {     // Mencetak data
            cout.precision(2);
            vector<MHS>::iterator it;
            for (it=list.begin(); it!=list.end(); ++it) {
                cout << it->nim << " " << it->usia << " "
                     << it->jenkel << " " << fixed << it->ipk << endl;
            }
        }
        void swap(int a, int b);  // Menukar posisi data
};

int main()
{
    MHS dt[]={{"G64208762",19,2,3.87}, {"G64208765",20,1,2.71}};
    myMhs obj(2, dt);

    obj.getAllData();
    int q, a, b;
    cin >> q;
    for (int i=0; i<q; i++)
    {
	cin >> a >> b;
	obj.swap(a-1, b-1);
    }
    obj.printAllData();
    return 0;
}
void myMhs::getAllData() 
{
    int kasus;
    cin >> kasus;
    string p_nim;
    int p_usia, p_jenkel;
    float p_ipk;
    for (int i=0; i<kasus; i++)
    {
    	cin >> p_nim >> p_usia >> p_jenkel >> p_ipk;
        MHS dt;
    	dt.nim = p_nim;
    	dt.usia = p_usia;
    	dt.jenkel = p_jenkel;
    	dt.ipk = p_ipk;
        list.push_back(dt);
    }
}
void myMhs::swap(int a, int b)
{
    MHS t = list[a];
    list[a] = list[b];
    list[b] = t;
}