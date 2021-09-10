#include <iostream>
#include <cstdio>
#include <new>

using namespace std;
 
class Ruang2D
{
   	protected:
   		int sisi1;
   		int sisi2;
   		int sisi3;
   		int sisi4;
   	public:
   		virtual double luas() = 0;
                virtual int keliling() = 0;
   		void setSisi(int s1=0, int s2=0, int s3=0, int s4=0) 
   		{ 
   			sisi1=s1; sisi2=s2; sisi3=s3; sisi4=s4;
   		}
};
class Segiempat:public Ruang2D {
      
      public:
         void setSisi(int a, int b) {
			 sisi1 = a; 
			 sisi2 = b;
			 }
         double luas(){ return sisi1 * sisi2; }
         int keliling() { return (sisi1+sisi2)*2; }
};

class Segitiga:public Ruang2D {

      public:

         void setSisi(int a, int b, int c){
            sisi1 = a;
            sisi2 = b;
            sisi3 = c;
         }
         double luas() {return sisi1*sisi2/2; }
         int keliling() {return sisi1+sisi2+sisi3;}

};



int main()
{
   int a,b,c;
   Segiempat s1;
   Segitiga s2;
   scanf("%d %d %d", &a, &b, &c);
   s1.setSisi(a,b);
   s2.setSisi(a,b,c);

   printf("%d %.2f\n", s1.keliling(), s1.luas());
   printf("%d %.2f\n", s2.keliling(), s2.luas());
   return 0;
}
