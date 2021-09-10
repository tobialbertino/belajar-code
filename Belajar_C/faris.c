#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (){
    char all[1000];
    int n,cek;
    scanf ("%d ", &n);
    for (int i=0; i<n; i++){
        fgets(all, sizeof(all), stdin);
        for (int j=2; j<strlen(all);j++){
            if (all[j]==all[j-2]){
                cek=1;
            }
            if (all[j]==all[j-1]){
                if (all[j-2]==all[j+1]){
                    cek=1;
                }
            }
        }
    if (cek==1) {printf ("YA\n");cek=0;}
    else {printf ("TIDAK\n");}
    }
}

