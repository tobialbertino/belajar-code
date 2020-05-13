#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {
    int counter=0,n,i;
    char ch[300];
    char *a1;

    scanf("%d ",&n);
    for(i=0;i<n;i++){
        fgets(ch,sizeof(ch),stdin);
        a1=strtok(ch," \n");
        while (a1 != NULL)
        {
            if (strlen(a1) >=4 ) counter++;
            //printf("%s--",a1);
            a1=strtok(NULL," \n");
        }
    }
    printf("%d\n",counter);
}

