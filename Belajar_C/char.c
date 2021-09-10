#include <stdio.h>
#include <string.h>
#define N 1000
int main () {
    char  in[N];
    int count=0,i;
    char a,b,huruf;
    scanf("%c %c ",&a,&b);

    while (huruf != '\n'){
        scanf("%c",&huruf);
        in[count]=huruf;
        count++;
    }
    for (i=0;i<count;i++){
        if (in[i]==toupper(a)) printf("%c",toupper(b));
        else if (in[i]==tolower(a)) printf("%c",tolower(b));
        else printf("%c",in[i]);
    }

}
