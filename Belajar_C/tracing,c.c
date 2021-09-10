#include <stdio.h>

int fpb(int a, int b) {
      if (b==0) return a;
      else return fpb(b, a%b);
   }
int kpk (int a, int b){
    int r;
    r=a*b/fpb(a,b);
    return r;
}
int main () {
    int a[2];
    int b[2];
    int i,penyebut,pembilang;
    for (i=0;i<2;i++){
        scanf("%d",&a[i][j]);
    }
    for (i=0;i<2;i++){
        scanf("%d",&b[i][j]);
    }
    penyebut=kpk(a[1],b[1]);
    pembilang=(penyebut/a[1]*a[0])+(penyebut/b[1]*b[0]);

    print("%d %d\n",pembilang,penyebut);
}
