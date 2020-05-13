#include <stdio.h>
int main()
{
   int max,min,berat,n;
    scanf("%d",&berat);
   while (berat != -1){
        max=berat;
        min=berat;
       while (berat != -1 && berat != 0){
            if (berat >=max) max=berat;
            else min=berat;
            scanf("%d",&berat);
       }
       if (berat == 0){
       printf("%d %d\n", min, max);
       scanf("%d",&berat);
       }
   }
    if (berat == -1)
        printf("%d %d\n", min, max);
}
