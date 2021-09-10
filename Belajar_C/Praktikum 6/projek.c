#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define T 2

int N, A[500];
// pthread_mutex_t mutex;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *fibonacci(void *arg){
	int *A = (int*)arg;				// cast void* --> int*
	int i;
	
	for(i = 0; i <= N/T; i++){
		pthread_mutex_lock(&mutex); 
		A[i] = A[i-1] + A[i-2]; 
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

int main(){
	pthread_t t[T];
	scanf("%d", &N);
	// pthread_mutex_init(&mutex, NULL);
	
	int i;
	A[0] = 0; 
	A[1] = 1; 
	
	for (i = 0; i < T; i++)
		pthread_create(&t[i], NULL, fibonacci, &A[(i*N/T) + 2]);

	for (i = 0; i < T; i++)
		pthread_join(t[i], NULL);

	for (i = 0; i < N; i++){
		printf("%d, ",A[i]);
	}
	printf("%d\n", A[N]);
	return 0;
}


