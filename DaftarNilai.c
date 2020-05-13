#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main () {
    int n,i,besar=0,urutan=0;
    char ch[100];
    scanf("%d ",&n);
    //char *nim1[n][10],*nama1[n][32],*jenis1[n][2],*uts1[n][4],*uas1[n][4];
    char nim[n][11],nama[n][50],jenis[n][2],uts[n][4],uas[n][4];
    char *a,*b,*c,*d,*e;
    int uts0,uas0;
    double rata[n];

    for(i=0;i<n;i++){
        fgets(ch,sizeof(ch),stdin);
        a=strtok(ch,",\n");
        strcpy(nim[i],a);
        b=strtok(NULL,",\n");
        strcpy(nama[i],b);
        c=strtok(NULL,",\n");
        strcpy(jenis[i],c);
        d=strtok(NULL,",\n");
        strcpy(uts[i],d);
        e=strtok(NULL,",\n");
        strcpy(uas[i],e);
        //ambil nilai int uts uas
        uts0=atoi(uts[i]);
        uas0=atoi(uas[i]);
        rata[i]=(1.0*uts0+uas0)/2;
    }
    //test potongan
    /*for(i=0;i<n;i++){
        printf("%s--%s--%s--%s--%s\n",nim[i],nama[i],jenis[i],uts[i],uas[i]);
    }
    for(i=0;i<n;i++){
        printf("%.2lf\n",rata[i]);
    }*/
    //cek urutan terbesar
    for(i=0;i<n;i++){
        if (rata[i] > besar) {
            besar = rata[i];
            urutan=i;
        }
    }
    printf("%s\n%s\n%s\n%.2lf\n",nim[urutan],nama[urutan],jenis[urutan],rata[urutan]);
}



