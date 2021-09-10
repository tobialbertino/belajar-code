#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>

#define SIZE 100000
using namespace std;

class Person {
   protected:
      string nama;   // nama
      char jk;       // jenis kelamin
      int usia;      // usia (tahun)
      string kota;   // kota lahir
   public:
      void set(string n, char j, int u, string k) { 
         nama = n;
         jk = j;
         u = usia;
         k = kota;
      }
      string getNama() {  };
      char getSex();
      int getUsia();
      string getKota();
};

class male::public Person
{
protected:
   vector<int> L;
public:
   void setMale()

};
class female::public Person
{
protected:
   vector<int> P;
};

int main () {
   char str[54];

   fgets(str, sizeof(str), stdin);
   
}