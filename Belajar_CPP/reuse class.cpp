#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
double phi = 3.14;
class Titik {
      double x,y;
      public:
         void set(double p, double q) { x=p; y=q; }
         double getX() { return x; }
         double getY() { return y; }
         void print() { cout<<"("<<x<<","<<y<<")"; }
};

class Lingkaran:public Titik{
	Titik p;
   	double r;

      public:
      	void setR(double a) { r = a; }
      	void setLingkaran(){
      		double a, b, c;
      		cin >> a >> b >> c;
      		p.set(a,b);
      		setR(c);
      	}
      	double luasL(){
      		double luas= phi * r * r;
      		return luas;
      	}
      	double kelilingL(){
      		double keliling = 2 * phi * r;
      		return keliling;
      	}
};

class Segitiga:public Titik {
      Titik A,B,C; 

      public:
      	void setSegitiga(){
      		double a,b,c,d,e,f;
      		cin >>a>>b>>c>>d>>e>>f;
      		A.set(a,b);
      		B.set(c,d);
      		C.set(e,f);
      	}
      	double keliling3(){
      		double a, b, c, keliling;
            a = sqrt( pow((A.getX() - B.getX()), 2) + pow((A.getY() - B.getY()), 2) );
            b = sqrt( pow((B.getX() - C.getX()), 2) + pow((B.getY() - C.getY()), 2) );
            c = sqrt( pow((C.getX() - A.getX()), 2) + pow((C.getY() - A.getY()), 2) );
            keliling = a+b+c;
            return keliling;
      	}
      	double luas3(){
      		double a, b, c, s, luas;
      		a = sqrt( pow((A.getX() - B.getX()), 2) + pow((A.getY() - B.getY()), 2) );
            b = sqrt( pow((B.getX() - C.getX()), 2) + pow((B.getY() - C.getY()), 2) );
            c = sqrt( pow((C.getX() - A.getX()), 2) + pow((C.getY() - A.getY()), 2) );
            s = keliling3() / 2;
            luas = sqrt( s*((s-a)*(s-b)*(s-c)) );
            return luas;
      	}      
   };

int main(){
	int n,m,i, countKO=0,countLO=0,countK3=0,countL3=0;
	double totalLO = 0, totalL3 = 0, totalKO=0, totalK3 = 0;
	double rataLO, rataL3, rataKO, rataK3;
	
	cin >> n >> m;
	double lO[n];
	double kO[n];
	double l3[m];
	double k3[m];
	Lingkaran L;
	Segitiga S;
	for (i=0; i<n; i++){
		L.setLingkaran();
		kO[i] = L.kelilingL();
		lO[i] = L.luasL();
		totalKO += kO[i];
		totalLO += lO[i];
	}
	rataKO = totalKO / n;
	rataLO = totalLO / n;
	for (i=0; i<m; i++){
		S.setSegitiga();
		k3[i] = S.keliling3();
		l3[i] = S.luas3();
		totalK3 += k3[i];
		totalL3 += l3[i];
	}
	rataK3 = totalK3 / m;
	rataL3 = totalL3 / m;

	for(i=0; i<n; i++){
		if (kO[i] > rataKO){ countKO++; }
		if (lO[i] > rataLO){ countLO++; }
		if (k3[i] > rataK3){ countK3++; }
		if (l3[i] > rataL3){ countL3++; }
	}
	cout << countLO <<" "<< countL3 << endl;
	cout << countKO <<" "<< countK3 << endl;
	
   return 0;

} 
