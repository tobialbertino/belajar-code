#include <stdio.h>
#define N 100000
void tukar(int *a, int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void bubblesort(int a[],int n){
    int i,j;
    for (i=0;i<n-1;i++){
        for (j=0;j<n-i-1;j++){
            if (a[j] < a[j+1]){
                tukar(&a[j], &a[j+1]);
            }
        }
    }
}
int main () {
    int a[N];
    int b[N];
    int c[N];
    int n,temp=0,i,selisih=0,hasil=0;
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    b[temp++]=a[0];  // menyimpan nilai awal
    for (i=1; i<n-1; i++){
        if((a[i-1] < a[i]) && (a[i] > a[i+1])) {
                b[temp++]=a[i];
        }
        else if ((a[i-1] > a[i]) && (a[i] < a[i+1])){
                b[temp++]=a[i];
        }
        /*if (a[i] > a[i+1]){
                b[temp++]=a[i];
        }
        if (a[i] < a[i+1]){
            b[temp++]=a[i];
        }
        */
    }
    //menyimpan nilai puncak dan lembah
    b[temp++]=a[n-1]; //simpan nilai terakhir
    /*
    for (i=0; i<temp; i++){
        printf("beda %d\n",b[i]);
        }
    for (i=0; i<temp-1; i++){
        printf(" selisih %d\n",c[i]);
    }
    */
    for (i=0; i<temp-1; i++){
        selisih=b[i+1]-b[i];
        if (selisih < 0){
            selisih=selisih*-1;
        }
        c[i]=selisih;
        if (c[i] > hasil) hasil=c[i];
    }


    printf("%d\n",hasil);
}
