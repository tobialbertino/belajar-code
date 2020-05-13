#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main () {
    int n,i,count=-1;
    scanf("%d ",&n);
    char warnajumlah[n][1000];
    char warna[n][10];
    char jumlah[n][1000];
    char *a;
    char input[10];
    int _jumlah[n];
    int totaljumlah[n],kurang[n];
    for (i=0;i<n;i++){// baca inout
        fgets(warnajumlah[i],sizeof(warnajumlah),stdin);
    }// potongan warna dan jumlah
     //test input
    /*for (i=0;i<n;i++){
        printf("input-%s",warnajumlah[i]);
    }*/
    for (i=0;i<n;i++){
        a=strtok(warnajumlah[i]," \n");
        strcpy(warna[i],a);
        a=strtok(NULL," \n");
        strcpy(jumlah[i],a);
    }
    // test potongan
    /*for (i=0;i<n;i++){
        printf("potongan--%s--%s\n",warna[i],jumlah[i]);
    }*/
    for (i=0;i<n;i++){
        _jumlah[i]=atoi(jumlah[i]);
    }
    // unah ke integer
    /*for (i=0;i<n;i++){
        printf("INTEGER WARNA-%d\n",_jumlah[i]);
    }*/
    //set total nilai =0
    for (i=0;i<n;i++){
        totaljumlah[i]=0;
    }
    //baca inputan akhir STOP
    fgets(input,sizeof(input),stdin);
    while (strcmp(input,"STOP\n") != 0){
        for (i=0;i<n;i++){
            if (strcmp(strtok(input," \n"),warna[i]) == 0)
                totaljumlah[i]++;
            //printf("SAMAKAN--%s--%s (warna %d)\n",input,warna[i],i);// TEST PERSAMAAN KEDUA STRING
        }

        fgets(input,sizeof(input),stdin);
        //if (strcmp(input,"STOP\n") == 0) break;
    }
    //test jumlah warna // error nilai awal>BARIS 40
    for (i=0;i<n;i++){
        //printf("Msukan input jml warna--%d\n",totaljumlah[i]);
    }
    for (i=0;i<n;i++){ //cari nilai yang kurang
        kurang[i]=0; //set nilai awal=0
        if (totaljumlah[i]<_jumlah[i]){
            kurang[i]=_jumlah[i]-totaljumlah[i];
            count=1;
        }
    }
    if(count == -1)
        printf("LENGKAP\n");
    else {
        for(i=0;i<n;i++){
            if (kurang[i]>0)
                printf("%s %d\n",warna[i],kurang[i]);
        }
    }
}
