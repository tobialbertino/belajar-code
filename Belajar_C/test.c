#include <stdio.h>

int main () {
    int a[101]={0};
    int nilai,count=1,i,n;

    scanf("%d",&nilai);
    while (nilai != 0){
        n=nilai;
        a[n]=count++;
        scanf("%d",&nilai);
    }

    for (i=100;i>=0;i--){
        if (a[i] != 0)
            printf("%d\n",a[i]);
    }
    for (i=100;i>=0;i--){
        printf("%d - %d\n",i,a[i])
    }
}
