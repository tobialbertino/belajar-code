#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
struct mhs
{
    char nim[11];
    int usia, jenkel;
    float ip;
};
typedef struct mhs MHS; //Penyingkatan menjadi MHS...(bebas)tipe data baru

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
//-------------------------------------------------------------------------------------

void print_struct (int n, MHS no[]) {
	int i;
	for (i = 0; i <n; i++) {
		cout << no[i].nim <<" "<< no[i].usia <<" "<< no[i].jenkel  <<" "<< fixed << setprecision(2) << no[i].ip << endl;
	}
}

int main(){
	int n,i,nTukar,a,b;
	cin >> n;
	MHS no[n];			//declare jumlah tipeData MHS sebanyak n / declare array no[i]
	for(i=0; i<n; i++){	//input data dari no[0]
		cin >> no[i].nim >> no[i].usia >> no[i].jenkel >> no[i].ip;
	}
	/*for(i=0; i<n; i++){	//print data
		cout << no[i].nim <<" "<< no[i].usia <<" "<< no[i].jenkel  <<" "<< no[i].ip << endl;
	}*/
	cin >> nTukar;
	for(i=0; i<nTukar; i++){
		cin >> a >> b;
		swap(no[a-1], no[b-1]);
	}
	/*for(i=0; i<n; i++){	//print data struct
		cout << no[i].nim <<" "<< no[i].usia <<" "<< no[i].jenkel  <<" "<< fixed << setprecision(2) << no[i].ip << endl;

	}
	*/
	print_struct(n, no);
}
