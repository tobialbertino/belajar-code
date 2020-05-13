#include <stdio.h>
struct balok {
   double panjang  ;
   double lebar;
   double tinggi;
};
typedef struct balok Balok;

int main() {
    double jumlah=0;
    int n,i,urut,total=0;
    scanf("%d", &n);
    //declare array struct
    Balok in[n];
    double volume[n]; //simpan volume
    for (i=0; i<n; i++){
        scanf("%lf",&in[i].panjang);
        scanf("%lf",&in[i].lebar);
        scanf("%lf",&in[i].tinggi);
        volume[i]=in[i].panjang*in[i].lebar*in[i].tinggi;
    }/*
    for (i=0; i<n; i++){
        printf("%lf %lf %lf Volume=%lf\n",in[i].panjang,in[i].lebar,in[i].tinggi,volume[i]);
    }*/
    scanf("%d",&urut);
    while (urut != -9){
        jumlah=jumlah+volume[urut-1];
        total++;
        scanf("%d",&urut);
    }
    printf("%.4lf\n",jumlah/total);
}
