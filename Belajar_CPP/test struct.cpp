#include <iostream>
#include <cstdio>
using namespace std;
struct mhs
{
    char nim[10];
};
typedef struct mhs MHS;

void tukar(int *a, int *b){
	MHS temp;
	temp = a;
	a = b;
	b = temp;
}

int main(){
	int n,i,nTukar;
	cin >> n;
	MHS no[n];	//declare jumlah MHS
	MHS temp;  //MHS temp
	for(i=0; i<n; i++){	//input data
		cin >> no[i].nim;
	}
	for(i=0; i<n; i++){	//print data
		cout << no[i].nim << endl;
	} cout << endl;

	temp = no[0];
	no[0] = no[1];
	no[1] = temp;

	for(i=0; i<n; i++){	//print data
		cout << no[i].nim << endl;
	} cout << endl;
}
