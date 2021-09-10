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
        double rataNum(int n) {
            double b = 0.0, i;
            for ( i = 0; i<n; i++){
                b += v[i];
            }
            if (sizeNum() != 0){
                b = (b*1.0)/sizeNum();
                return b;
            }
            else
                return 0;   
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
    //cout << v.sizeNum() <<endl;
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
    //cout << v.sizeNum() <<endl;
    rata[1] = v.rataNum(v.sizeNum());

    cout << a <<' '<< b << endl;
    if (a != 0 && b != 0)
        cout << fixed << setprecision(2) << rata[0] <<" "<< fixed << setprecision(2) << rata[1] << endl;
    else if (b == 0 && a!=0)
        cout << fixed << setprecision(2) << rata[0] << " -9.99" << endl;
    else if (a == 0 && b == 0)
         cout <<"-9.99 -9.99" << endl;
			
    return 0;
}
