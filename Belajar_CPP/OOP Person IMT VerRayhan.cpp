#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
using namespace std;

class person{
	private:
		string nama;
		int usia;
		int tinggi;
		double berat;
	public:
		void setPerson(string N, char A, int H, float W){
			nama = N;
			usia = A;
			tinggi = H;
			berat = W;
		}
		int checkH(double mean){
			if(tinggi>mean) return 1;
			else return 0;
		}
		void cetakDat(){
			cout<<fixed<<nama<<' '<<usia<<' '<<tinggi<<' '<<setprecision(2)<<berat<<' '<<setprecision(2)<<getIMT();
		}
		double getBerat(){
			return berat;
		}
		double getIMT(){
			double meter = tinggi/100.0;
			return berat/(meter*meter);
		}
		int getStatusGizi(){
			if(getIMT()>=28.0){ cout<<" sangat gemuk"; return 4; }
			else if(getIMT()>=25.0){ cout<<" gemuk"; return 3; }
			else if(getIMT()>=18.5){ cout<<" normal"; return 2; }
			else if(getIMT()>=17.0){ cout<<" kurus"; return 1; }
			else { cout<<" sangat kurus"; return 0; }
		}
};

typedef person org;

int main(){
	org orang[101];
	string nama;
	double berat,meanh;
	int n,usia,tinggi,sumh=0,sumorg=0,stat[5]={0};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>nama>>usia>>tinggi>>berat;
		orang[i].setPerson(nama,usia,tinggi,berat);
		sumh+=tinggi;
	}
	meanh = sumh/(n*1.0);
	for(int i=0;i<n;i++){
		orang[i].cetakDat();
		stat[orang[i].getStatusGizi()]++;
		cout<<endl;
		sumorg += orang[i].checkH(meanh);
	}
	cout<<fixed<<setprecision(2)<<meanh<<endl;
	cout<<sumorg<<endl;
	cout<<stat[0]<<' '<<stat[1]<<' '<<stat[2]<<' '<<stat[3]<<' '<<stat[4]<<endl;
}
