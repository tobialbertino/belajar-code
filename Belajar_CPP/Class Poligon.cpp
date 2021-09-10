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
        vector<double> x;
        vector<double> y;
        int nEdge;
    // member functions
    public:
        void clearV() { 
            x.clear(); 
            y.clear(); 
        }
        void set(int n) { nEdge = n; }
    
        void setPoligon(){
            double a, b, i;
            for (i=0; i<nEdge; i++){
                cin >> a >> b;
                x.push_back(a);
                y.push_back(b);
            }
        }
        void print(){
            int i;
            for (i=0; i<nEdge; i++){
                cout << x[i] <<" "<< y[i] << endl;
            }
 
        }
        double getPX(double i){ return x[i]; }
        double getPY(double i){ return y[i]; }
        double keliling() {
            double i;
            double total = 0.00, d;
            for(i=0; i<nEdge-1; i++){
                d = sqrt( pow((x[i] - x[i+1]), 2) + pow((y[i] - y[i+1]), 2) );
                total = total*1.0 + d;
            }
            d = sqrt( pow((x[i] - x[0]), 2) + pow((y[i] - y[0]), 2) );
            total += d;
            return total;
        }
};
 
int main(){
    int n;
    Poligon p;
 
    cin >> n;
    p.set(n);
    p.setPoligon();
    double awalX = p.getPX(0);
    double awalY = p.getPY(0);
    double akhirX = p.getPX(n-1);
    double akhirY = p.getPY(n-1);
 
    cout <<"["<< fixed << setprecision(2) <<awalX<<","<< fixed << setprecision(2) <<awalY<<"]-["
    << fixed << setprecision(2) << akhirX <<","<< fixed << setprecision(2) << akhirY <<"]"<< endl;
    cout << fixed << setprecision(2) << p.keliling() << endl;;
     
    return 0;
}