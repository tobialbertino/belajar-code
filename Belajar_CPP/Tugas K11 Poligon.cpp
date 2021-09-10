#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

#define SIZE 100
using namespace std;

class Poligon 
{
	// data members
	protected:
		vector<float> x;
    	vector<float> y;
    	int nEdge;
    // member functions
    public:
        void clearV() { 
			x.clear(); 
			y.clear(); 
		}
    	void set(int n) { nEdge = n; }
    	void print(){
    		int i;
    		for (i=0; i<nEdge; i++){
    			cout << x[i] <<" "<< y[i] << endl;
    		}
    	}
    	float keliling() {
    		float i;
    		float total = 0.00, d;
    		for(i=0; i<nEdge-1; i++){
    			d = sqrt( pow((x[i] - x[i+1]), 2) + pow((y[i] - y[i+1]), 2) );
    			total = total*1.0 + d;
    		}
    		d = sqrt( pow((x[i] - x[0]), 2) + pow((y[i] - y[0]), 2) );
    		total += d;
            //cout <<"keliling = "<< total <<endl;
    		return total;
    	}
};
class Segitiga:public Poligon
{
	protected:
	public:
		void setSegitiga(){
			nEdge = 3;
            float a, b, i;
            for (i=0; i<nEdge; i++){
                cin >> a >> b;
                x.push_back(a);
                y.push_back(b);
            }
		}
        float luas3(){
            float s, a, b, c, luas;
            s = 0.5 * keliling();
            a = sqrt( pow((x[0] - x[1]), 2) + pow((y[0] - y[1]), 2) );
            b = sqrt( pow((x[1] - x[2]), 2) + pow((y[1] - y[2]), 2) );
            c = sqrt( pow((x[0] - x[2]), 2) + pow((y[0] - y[2]), 2) );
            luas = sqrt( s*((s-a)*(s-b)*(s-c)) );
            return luas;
        }
        
};
class Segiempat:public Poligon
{
    protected:
    public:
        void setSegiempat(){
            nEdge = 4;
            float a, b, i;
            for (i=0; i<nEdge; i++){
                cin >> a >> b;
                x.push_back(a);
                y.push_back(b);
            }
        }
        float luas4(){ 
            /*float a, b, c, d, luas; // FIX
            a = (x[0] * y[1]) - (x[1] * y[0]);
            b = (x[1] * y[2]) - (x[2] * y[1]);
            c = (x[2] * y[3]) - (x[3] * y[2]);
            d = (x[3] * y[0]) - (x[0] * y[3]);
            luas = (a+b+c+d) / 2;
            if (luas < 0) { luas *= -1; }
            return luas;
            */
            float s1, s2, a, b, c, d, z, luas;		//sudah OK
            a = sqrt( pow((x[0] - x[1]), 2) + pow((y[0] - y[1]), 2) );
            b = sqrt( pow((x[1] - x[2]), 2) + pow((y[1] - y[2]), 2) );
            c = sqrt( pow((x[2] - x[3]), 2) + pow((y[2] - y[3]), 2) );
            d = sqrt( pow((x[3] - x[0]), 2) + pow((y[3] - y[0]), 2) );
            z = sqrt( pow((x[0] - x[2]), 2) + pow((y[0] - y[2]), 2) );
            s1 = 0.5 * (a+b+z);
            s2 = 0.5 * (c+d+z);
            luas = sqrt( s1*(s1-a)*(s1-b)*(s1-z) ) + sqrt( s2*(s2-c)*(s2-d)*(s2-z) );
            return luas;
            
            /*float s, a, b, c, d, luas;    //masih salah "Jika Persegi Beraturan"
            s = 0.5 * keliling();
            a = sqrt( pow((x[0] - x[1]), 2) + pow((y[0] - y[1]), 2) );
            b = sqrt( pow((x[1] - x[2]), 2) + pow((y[1] - y[2]), 2) );
            c = sqrt( pow((x[2] - x[3]), 2) + pow((y[2] - y[3]), 2) );
            d = sqrt( pow((x[3] - x[0]), 2) + pow((y[3] - y[0]), 2) );
            luas = sqrt( ((s-a)*(s-b)*(s-c)*(s-d)) );
            return luas;
            */
        }
        
};

int main(){
	int n, m, i, count3=0, count4=0;
    float totalL3 = 0.0, totalL4 = 0.0, rataL3, rataL4;
    float l3[SIZE] ;
    float l4[SIZE] ;

    Segitiga A;
    cin >> n;
    
    for (i = 0; i<n; i++){
        A.setSegitiga();
        l3[i] = A.luas3();
        totalL3 += A.luas3();
        A.clearV();
    }
    rataL3 = totalL3 / n;

    Segiempat B;
    cin >> m;
    
    for (i=0; i<m; i++){
        B.setSegiempat();
        l4[i] = B.luas4();
        //cout << "luas = " << l4[i] << endl;
        totalL4 += B.luas4();
        B.clearV();
    }
    rataL4 = totalL4 / m;

    for(i=0; i<n; i++){
        if (l3[i] > rataL3) count3++;
        if (l4[i] > rataL4) count4++;
    }
    cout <<fixed <<setprecision(2)<< rataL3 <<" "<<fixed<<setprecision(2)<< rataL4 << endl;
    cout << count3 <<" "<< count4 << endl;
    
}
