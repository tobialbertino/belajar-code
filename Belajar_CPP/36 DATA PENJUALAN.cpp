#include <iostream>
#include <iomanip>
#include <cstring>
#include <map>

using namespace std;

struct record {
   int jumlah;   // jumlah item barang
   int total;    // nilai rupiah
};

typedef struct record ITEM;
typedef pair<string,int> P;

class Produk 
{
    map<string,int> list;     // Daftar kode barang dan harga satuan per unit
    public:
        // Fungsi membaca daftar kode barang dan harga satuan
        void initProduk() {
           string item; int n,harga;
           cin >> n;
           while (n--) {
              cin >> item >> harga;
              list.insert(P(item,harga));
           }
        }

        // Fungsi mendapatkan harga satuan dari suatu item barang
        // Nilai 0 untuk item barang yang tidak ditemukan
        int getHarga(string item) {
           if (list[item]) return list[item];
           else return 0;
        }
};

class Penjualan {
    Produk dt;                    // Daftar harga satuan barang
    map<string,ITEM> penjualan;   // Daftar penjualan
    public:
       Penjualan() { dt.initProduk(); }

       // Fungsi membaca data penjualan dan memasukkan ke dalam Daftar penjualan
       void addPenjualan() { .... }

       // Fungsi mencetak data penjualan dan total nilai penjualan
       void print() { .... }
};

int main()
{
    Penjualan p;
    p.addPenjualan();
    p.print();
    return 0;
}