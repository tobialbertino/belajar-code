#include <stdio.h>
int main()
{
    int min,max,i,n;

    scanf("%d",&i);
    min=i;
    max=i;
    while (i!=-1)
    {
        while(i!=0)
        {
            i;
            if (i<=min) min=i;
            if (i>=max) max=i;
            scanf("%d",&i);
        }
        printf("%d %d\n",min,max);
        scanf("%d",&i);
        max=i;
        min=i;

    }
    printf("%d %d\n",min,max);
}
