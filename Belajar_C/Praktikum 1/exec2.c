#include<stdlib.h>

int main (){
    execlp("cal", "cal", "6", "2020", NULL);

    return 0;
}