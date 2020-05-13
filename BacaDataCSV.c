#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 50
struct mhs {
    char nama[50];
    char nim[10];
    int usia, jenkel;
    float ip;
};
typedef struct mhs MHS;

void hapusChar(char str[], char t)
{
    int i,j;
    i = 0;
    while(i<strlen(str)) {
        if (str[i]==t) {
        for (j=i; j<strlen(str); j++)
            str[j]=str[j+1];
        }
        else i++;
    }
}

int main () {
    int n=0,i;
    char st[256];
    MHS st[SIZE];
    char *t;
    while( fgets(st, sizeof(st), stdin) ) {
        t=strtok(st,","); hapusChar(t,’"’);
        strcpy(list[n].nama,t);
        t=strtok(NULL,","); hapusChar(t,’"’);
        strcpy(list[n].nim,t);
        t=strtok(NULL,","); list[n].usia=atoi(t);
        t=strtok(NULL,","); list[n].jenkel=atoi(t);
        t=strtok(NULL,","); list[n].ip=atof(t);
        n++;
        }
}
