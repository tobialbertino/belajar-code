#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <new>
#include <sstream>
using namespace std;

class NIM
{
	string value;
	public:
		NIM() { value=""; }
		void setNIM(string p) { value=p; }
		char getFakultas();                  // Mendapatkan kode Fakultas
		string getNIM();                     // Mendapatkan nilai NIM
		string getProdi();                   // Mendapatkan kode Program Studi
		int getTahunMasuk();                 // Mendapatkan Tahun Masuk
};

string NIM::getNIM(){
    return value;
}
char NIM::getFakultas(){
    return(value[0]);
}
string NIM::getProdi(){
    return(value.substr(0,3));
}
int NIM::getTahunMasuk(){
    string y = value.substr(3,2);
    stringstream year(y);
    int tahun = 0;
    year>>tahun;
    if(tahun>62) tahun+=1900;
    else tahun+=2000;
    return tahun;
}

int main()
{
	NIM *mhs = new NIM;
	char st[10];
	while (scanf("%s",st)!=EOF)
	{
		mhs->setNIM(st);
		cout << mhs->getNIM() << " " << mhs->getFakultas() << " " 
	         << mhs->getProdi() << " " << mhs->getTahunMasuk()-1963 << endl;
	}
	return 0;
}
