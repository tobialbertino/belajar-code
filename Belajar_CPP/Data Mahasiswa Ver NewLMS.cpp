#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// Definisi tipe data
struct mhs
{
	char nim[10];
	int usia, jenkel;
	float ipk;
};
typedef struct mhs MHS;

// Fungsi menukar record data mhs
void tukar(MHS *a, MHS *b)
{
	MHS t = *a;
	*a = *b;
	*b = t;
}

// Fungsi mencetak daftar mhs
void print(MHS d[100], int n)
{
	cout.precision(2);
	for (int i=0;i<n;i++)
	{
		cout << d[i].nim << " " << d[i].usia
		     << " " << d[i].jenkel << " " << fixed
		     << d[i].ipk << endl;
	}
}

// Program utama
int main()
{
	// Membaca record data sebanyak n
	MHS list[100];
	int n;
	cin >> n;
	char nim[10];
	int usia, jenkel;
	float ipk;
	for (int i=0; i<n; i++)
	{
		cin >> nim >> usia >> jenkel >> ipk;
		strcpy(list[i].nim,nim);
		list[i].usia = usia;
		list[i].jenkel = jenkel;
		list[i].ipk = ipk;
	}

	// Membaca baris penukaran posisi data
	int query;
	cin >> query;
	int pos1,pos2;
	while(query--)
	{
		cin >> pos1 >> pos2;
		tukar(&list[pos1-1], &list[pos2-1]);
	}

	// Cetak daftar mhs setelah penukaran
	print(list, n);
	return 0;
}