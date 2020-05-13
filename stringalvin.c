#include<stdio.h>
#include<string.h>

int main()
{
char str[10000],*titik,string1[10000],string2[10000];
int n,i,lokasi,panjang,nilai;
    scanf("%d\n",&n);
    for(i=1;i<=n;i++)
        {
            str[0]='\0';
            string1[0]='\0';
            string2[0]='\0';
            gets(str);
            //printf("%s\n",str);
            panjang = strlen(str);
            titik = strchr(str,':');
            lokasi = titik-str+1;
            if(titik=='\0')
                printf("N\n");
            else
                {
                strncpy(string1,str,lokasi-1);
                string1[lokasi-1]='\0';
                strncpy(string2,&str[lokasi],(panjang-lokasi));
                string2[panjang-lokasi]='\0';
                nilai = strcmp(string1,string2);
                //printf("%s\n%s\n%d\n",string1,string2,nilai);
                 if(strlen(string1)>strlen(string2))
                    printf("L\n");
                 else if(strlen(string1)<strlen(string2))
                    printf("U\n");
                 else if(nilai==0)
                   printf("S\n");
                 else
                   printf("X\n");
                }
        }
}
