#include<stdio.h>
int main()
{
    int n,i,sum,a;
    scanf("%d",&n);
    i=1;
    sum=0;
    while(i<=n)
    {
        scanf("%d",&a);
        sum=sum+a;
        i++;
    }
    printf("%d\n",sum);
}
