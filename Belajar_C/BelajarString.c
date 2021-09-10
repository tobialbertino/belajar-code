#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {
    char ch1[200],a[200],b[200];
    char *a1;
    char *b1;
    int n,i;

    scanf("%d ",&n);
    for (i=0 ; i<n; i++) {
        fgets(ch1,sizeof(ch1),stdin);
        a1=strtok(ch1,":\n");

        b1=strtok(NULL,":\n");

        //printf("%s--%s\n",a1,b1); //test potongan
        if (b1 == '\0')
            printf("N\n");

        else if (strlen(a1) > strlen(b1)){
            printf("L\n");
        }
        else if (strcmp(a1,b1) ==0 ){
            printf("S\n");
        }
        else if (strlen(a1) < strlen(b1)){
            printf("R\n");
        }
        else if (strlen(a1) == strlen(b1) && strcmp(a1,b1) != 0 ){
            printf("D\n");
        }
    }
}
    //test
    /*for (i=0 ; i<n; i++) {
        printf("%s",ch1);
    }
    */

