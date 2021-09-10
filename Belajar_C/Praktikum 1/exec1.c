#include<stdlib.h>

int main (){
    execlp("ps", "ps", "-A", NULL);

    return 0;
}