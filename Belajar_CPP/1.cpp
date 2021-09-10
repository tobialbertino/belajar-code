#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

class A {
	private:
	   int a;
	public:
	   void setA(int p) { a=p; }
};
int main() {
	A o1;
	o1.setA(5);
	std::cout << o1.a << std::endl;
	return 0;
}