#include <iostream>
#include <iomanip> 
#include <vector>
#include <utility>
#include <cmath>
 
using namespace std;
typedef pair<double,double> Koordinat;
 
class Polygon : public vector<Koordinat> {
public:
    Koordinat get(int i) { return vector<Koordinat>::at(i); }
     
    void baca() {
        int n;
        double t1,t2;
        Koordinat titik;
        cin >> n;
        while(n--) {
            cin >> t1 >> t2;
            titik=make_pair(t1,t2);
            vector<P>::push_back(titik);
        }
    }
     
    double jarak(Koordinat t1, Koordinat t2) {
        double t=sqrt((t1.first-t2.first)*(t1.first-t2.first)+
                 (t1.second-t2.second)*(t1.second-t2.second));
        return t;
    }
     
    double keliling() {
        int i;
        Koordinat t=get(0); double sum=0;
        for(i=1;i<vector<Koordinat>::size();i++) {
            sum+=jarak(get(i-1),get(i));
        }
        sum+=jarak(get(i-1),get(0));
        return sum;
    }
     
    void cetak() {
        int n=vector<Koordinat>::size();
        cout << fixed << setprecision(2);
        cout << "[" << get(0).first << "," << get(0).second << "]-["
             << get(n-1).first << "," << get(n-1).second << "]\n";
        cout << keliling() << endl;
    }
};
 
int main()
{
    Polygon dt;
    dt.baca();
    dt.cetak();
    return 0;
}

// STL MAP

#include <ios>
#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
class Biodata {
   private:
      string nama;
      int usia;
   public:
      Biodata() { nama=""; usia=0; }
      void setBiodata(string nm, int u) {
         nama=nm; usia=u;
      }
      string getNama() { return nama; }
      int getUsia() { return usia; }
      void cetak() {
         cout << nama << ":" << usia << endl;
      }
};
int main()
{
   int n, usia;
   string nim, nama;
   Biodata bio;
   map<string, Biodata> Mhs;
   // Menyimpan nim dan Biodata mahasiswa
   cin >> n;
   for (int i=0; i<n; i++) {
      cin >> nim >> nama >> usia;
      bio.setBiodata(nama, usia);
      Mhs[nim] = bio;
   }
   // Menulis Biodata dengan nim tertentu
   Mhs["3374"].cetak();
   // Menulis daftar Biodata
   map<string, Biodata>::iterator it;
   for(it=Mhs.begin(); it!=Mhs.end(); ++it) {
       cout << (*it).first << ":";
       (*it).second.cetak();
   }
   return 0;
}
Jika diberikan input data:

5
5234 Mike 19
3374 Charlie 20
1923 David 21
7582 John 19
5328 Peter 20
Maka output program tersebut adalah:

Charlie:20
1923:David:21
3374:Charlie:20
5234:Mike:19
5328:Peter:20
7582:John:19

// STL SET

#include <iostream> 
#include <set> 
#include <iterator> 
using namespace std; 
int main() 
{ 
    set <int, greater <int> > gquiz1;        
 
    gquiz1.insert(40); 
    gquiz1.insert(30); 
    gquiz1.insert(60); 
    gquiz1.insert(20); 
    gquiz1.insert(50); 
    gquiz1.insert(50); // nilai ini tidak dimasukkan karena sudah ada dalam set 
    gquiz1.insert(10); 
    
    set <int, greater <int> > :: iterator itr; 
    cout << "\nThe set gquiz1 is : "; 
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
    cout << endl; 
     
    set <int> gquiz2(gquiz1.begin(), gquiz1.end()); 
     
    cout << "\nThe set gquiz2 after assign from gquiz1 is : "; 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
    cout << endl; 
    // remove all elements up to 30 in gquiz2 
    cout << "\ngquiz2 after removal of elements less than 30 : "; 
    gquiz2.erase(gquiz2.begin(), gquiz2.find(30)); 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
    // remove element with value 50 in gquiz2 
    int num; 
    num = gquiz2.erase (50); 
    cout << "\ngquiz2.erase(50) : "; 
    cout << num << " removed \t" ; 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
    cout << endl; 
     
    cout << "gquiz1.lower_bound(40) : "
        << *gquiz1.lower_bound(40) << endl; 
    cout << "gquiz1.upper_bound(40) : "
        << *gquiz1.upper_bound(40) << endl; 
     
    cout << "gquiz2.lower_bound(40) : "
        << *gquiz2.lower_bound(40) << endl; 
    cout << "gquiz2.upper_bound(40) : "
        << *gquiz2.upper_bound(40) << endl; 
    return 0; 
}

Output program tersebut adalah:

The set gquiz1 is :      60    50    40    30    20    10
The set gquiz2 after assign from gquiz1 is : 10      20    30    40    50    60
gquiz2 after removal of elements less than 30 : 30    40    50    60
gquiz2.erase(50) : 1 removed     30    40    60
gquiz1.lower_bound(40) : 40
gquiz1.upper_bound(40) : 30
gquiz2.lower_bound(40) : 40
gquiz2.upper_bound(40) : 60
