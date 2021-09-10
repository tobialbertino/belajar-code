#include <stdio.h>
#define N 100000
int main(){
    int n1,n2,i,j,k,temp;
    int a[N];
    scanf("%d",&n1);
    for (i=0;i<n1;i++){
        scanf("%d",&a[i]);
    }
     scanf("%d",&n2);
    for (i=0;i<n2;i++){
        scanf("%d",&a[i+n1]);
    }
    //urutan. source"https://www.sanfoundry.com/c-program-sorting-bubble-sort/"
    for (i = 0; i < n1+n2; i++){
        for (j = 0; j < (n1+n2 - i - 1); j++){
            if (a[j] > a[j + 1]){

                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

            }
        }
    }
    for (i=0;i<n1+n2;i++){
        printf("%d\n",a[i]);
    }


}
