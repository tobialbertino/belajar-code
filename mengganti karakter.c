#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define N 100000
int main () {
    char ch[N],tunjuk;
    int n,count=1,i;

    fgets(ch,sizeof(ch),stdin);
    n=strlen(ch);
    for(i=0;i<n-1;i++){
        if (toupper(ch[i]) == toupper(ch[i+1])){
            count++;
        }
        else {
            printf("%d%c",count,toupper(ch[i]));
            count=1;
        }
    }
    //printf("\n");
}
