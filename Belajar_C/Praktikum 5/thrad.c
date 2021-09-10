#include <stdio.h>
#include <pthread.h>
#define N 16
#define T 4

int sum = 0;

void *array_sum(void *arg) {
    int *A = (int*)arg;
    for (int i = 0; i < N/T; i++) {
        sum += A[i];
    }
    pthread_exit(NULL);
}

int main() {
    int A[N] = {68, 34, 64, 95, 35, 78, 65, 93,
                51, 67, 7, 77, 4, 73, 52, 91};
    pthread_t t[T];
    
    /* TODO: array sum */
    for (int i = 0; i < T; i++) {
        pthread_create(&t[i], NULL, array_sum, &A[i * N/T]);
    }
    for (int i = 0; i < N/T; i++) {
        pthread_join(t[i], NULL);
    }

    printf("%d\n", sum); 
    return 0;
}