#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main () {
    int i,umur,total=0,n;
    double rata;
    char ch[1001][41];

    scanf("%d ",&n);
    for (i=0;i<n;i++){
        fgets(ch[i],sizeof(ch),stdin);
        //strncpy(nomor,ch[i],5);
        umur=atoi(ch[i]);
        total+=umur;
        //printf("ch[%d]--%s\n",i,ch[i]);
   }
   rata=total*1.0/n;
   for (i=0;i<n;i++){
        printf("%s",ch[i]+2);
   }
   printf("%.2lf\n",rata);
}


