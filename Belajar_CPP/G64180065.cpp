#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>
#include <vector>
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
        void set(int n) { nEdge = n; }
        void print(){
            int i;
            for (i=0; i<nEdge; i++){
                cout << x[i] <<" "<< y[i] << endl;
            }
        }
        float keliling() {
            int i;
            float total=0, d;
            for(i=0; i<nEdge-1; i++){
                d = sqrt( pow((x[i] - x[i+1]), 2) + pow((y[i] - y[i+1]), 2) );
                total += d;
            }
            d = sqrt( pow((x[i] - x[0]), 2) + pow((y[i] - y[0]), 2) );
            total += d;
            return total;
        }
};
class Segitiga:public Poligon
{
    protected:
    public:
        void setSegitiga(int n){
            nEdge = 3;
            float a, b, N, i;
            N=n*3;
            for (i=0; i<N; i++){
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
            luas = sqrt( s*(s-a)*(s-b)*(s-c) );
            return luas;
        }
        
};
class Segiempat:public Poligon
{
    protected:
    public:
        void setSegiempat(int n){
            nEdge = 4;
            float a, b, N, i;
            N=n*4;
            for (i=0; i<N; i++){
                cin >> a >> b;
                x.push_back(a);
                y.push_back(b);
            }
        }
        float luas4(){
            float s, a, b, c, d, luas;
            s = 0.5 * keliling();
            a = sqrt( pow((x[0] - x[1]), 2) + pow((y[0] - y[1]), 2) );
            b = sqrt( pow((x[1] - x[2]), 2) + pow((y[1] - y[2]), 2) );
            c = sqrt( pow((x[2] - x[3]), 2) + pow((y[2] - y[3]), 2) );
            d = sqrt( pow((x[3] - x[0]), 2) + pow((y[3] - y[0]), 2) );
            luas = sqrt( (s-a)*(s-b)*(s-c)*(s-d) );
            return luas;
        }
        
};

int main(){
    int n, m, i, count3, count4;
    Segitiga A;
    cout.precision(2);
    
    float totalL3=0, totalL4 = 0, rataL3, rataL4;
    cin >>n;
    float l3[n] = {0};
    for (i = 0; i<n; i++){
        A.setSegitiga(n);
        l3[i] = A.luas3();
        totalL3 += A.luas3();
    }
    rataL3 = totalL3 / n;
    Segiempat B;
    cin >>m;
    float l4[m];
    for (i=0; i<m; i++){
        B.setSegiempat(m);
        l4[i] = B.luas4();
        totalL4 += B.luas4();
    }
    rataL4 = totalL4 / m;

    for(i=0; i<n; i++){
        if (l3[i] > rataL3) count3++;
        if (l4[i] > rataL4) count4++;
    }

    cout << rataL3 <<" "<< rataL4 << endl;
    cout << count3 <<" "<< count4 << endl;
}
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>

using namespace std;

class number
{
    // data members
    private:
        vector<int> v;
    // member functions
    public:
        number() {}
        ~number(){} 
        void addInt(int a){
            v.push_back(a);
        }
        int sizeNum() { return v.size();}
        void eraseNum(int a, int c) { 
            v.erase(v.begin()+(a-1-c));
        }
        int totalNum(int n)
        {
            int c = 0, i;
            for ( i = 0; i<n; i++){
                c += v[i];
            }
            return c;
        }
        int rataNum(int n) {
            int b = 0, i;
            for ( i = 0; i<n; i++){
                b += v[i];
            }
            b /= sizeNum();
            return b;
        }

};


int main()
{
    int bil, n, a, b; 
    double rata[2]={0};
    number v;
    
    cin >> bil;
    while (bil != -9){
        v.addInt(bil);
        cin >> bil;
    }
    //cout << v.size() <<endl;; 
    a = v.sizeNum();   
    rata[0] = v.rataNum(v.sizeNum());
    int count = 0;
    cin >> n;
    while (n != -9){
        v.eraseNum(n, count);
        count++;
        cin >> n;
    }
    b = v.sizeNum();
    //cout << v.size() <<endl;
    rata[1] = v.rataNum(v.sizeNum());

    cout << a <<" "<< b << endl;
    cout << fixed << setprecision(2) << rata[0] <<" "<< fixed << setprecision(2) << rata[1] << endl;
    return 0;
}
