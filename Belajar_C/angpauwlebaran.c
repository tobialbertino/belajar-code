#include<stdio.h>

int main(){
    int i, jumlah;
    int _50 = 0, _20 = 0, _10 = 0, _5 = 0, _2 = 0, _1 = 0, _100 = 0, _200 = 0;
    scanf("%d",&jumlah);

    while(jumlah > 0){
        if(jumlah/200 > 0){
            _200++;
            jumlah-=200;
        } else if (jumlah/100 > 0){
            _100++;
            jumlah-=100;
        }
            else if (jumlah/50 > 0){
            _50++;
            jumlah-=50;
        }
            else if (jumlah/20 > 0){
            _20++;
            jumlah-=20;
        }
            else if (jumlah/10 > 0){
            _10++;
            jumlah-=10;
        }
            else if (jumlah/5 > 0){
            _5++;
            jumlah-=5;
        }
            else if (jumlah/2 > 0){
            _2++;
            jumlah-=2;
        }
            else if (jumlah/1 > 0){
            _1++;
            jumlah-=1;
        }
    }
    if (_200 > 0)
    {
        printf ("200 %d\n",_200);
    }
    if (_100 > 0)
    {
        printf ("100 %d\n",_100);
    }
    if (_50 > 0)
    {
        printf ("50 %d\n",_50);
    }
    if (_20 > 0)
    {
        printf ("20 %d\n",_20);
    }
    if (_10 > 0)
    {
        printf ("10 %d\n",_10);
    }
    if (_5 > 0)
    {
        printf ("5 %d\n",_5);
    }
    if (_2 > 0)
    {
        printf ("2 %d\n",_2);
    }
    if (_1 > 0)
    {
        printf ("1 %d\n",_1);
    }


}
