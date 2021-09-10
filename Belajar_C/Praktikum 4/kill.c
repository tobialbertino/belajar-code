#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main() {
    pid_t child = fork();
    if (child == 0){
        while (1)
        {
            puts("child");
            sleep(1);
        }
    }
    else {
        sleep(5);
        kill(child, SIGTERM); // terminate
    }
    return 0;
}