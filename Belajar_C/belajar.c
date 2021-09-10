#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define N 100000
int main () {
   int n,i;
   char ch[500],ch1[500],ch2[500];
   char *p;
   scanf("%d ",&n);
   for (i=0;i<n;i++){
        fgets(ch,sizeof(ch),stdin);
        p=strtok(ch," :\n");
        strcpy(ch1,p);
        //printf("%s\n",ch1);
        strcpy(ch2,strtok(NULL," :\n"));
        //printf("%s\n",ch2);
        if (strcmp(ch1,ch2) == 0)
            printf("S\n");
        else if (strlen(ch1) < strlen(ch2))
            printf("U\n");
        else if (strlen(ch1) > strlen(ch2))
            printf("L\n");
        else
            printf("X\n");
   }
}
