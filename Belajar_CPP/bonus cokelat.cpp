#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
	long long int n, c;
	cin >> n;
	c = n;
	while ((c/5) > 0 ){
		n+= c/5 ;
		c= (c/5) + (c%5);
	}
	cout << n << endl;
}
