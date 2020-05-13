#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main () {
    int n,i,len,tru,j;
    char ch[1000];

    scanf("%d ",&n);
    for (i=0;i<n;i++){
        fgets(ch,sizeof(ch),stdin);
        len = strlen(ch);
        if (len>2){
            for (j=2;j<len;j++){
                if (tolower(ch[j-2]) == tolower(ch[j])){
                    tru=1;
                }
            }
        }
        if (tru == 1) {
            printf("YA\n");
            tru=0;
        }
        else printf("TIDAK\n");
    }
    //printf("\n");
}
