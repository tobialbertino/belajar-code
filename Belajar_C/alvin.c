#include<stdio.h>
#include<string.h>

int main()

{
    int i,n,nilai[1000],nilai2[1000],lengkap=0;
    scanf("%d\n",&n);
    char str[1000][1000],string[1000];
    for (i =1; i<=n; i++)
    {
        scanf("%s %d", str[i],&nilai[i]);
    }
    /*for(i=1;i<=n;i++)
    {
       printf("%s %d\n",str[i],nilai[i]);
    }*/
    scanf("%s",string);
    while(strcmp(string,"STOP")!=0)
        {
        for (i =1; i<=n; i++)
            {
            if(strcmp(str[i],string)==0)
                nilai2[i]++;
            }
        scanf("%s",string);
        }
    for (i =1; i<=n; i++)
    {
        if(nilai[i]!=nilai2[i])
            {
                printf("%s %d\n",str[i],(nilai[i]-nilai2[i]));
                lengkap =1;
            }
    }
    if(lengkap==0)
        printf("LENGKAP\n");
}
