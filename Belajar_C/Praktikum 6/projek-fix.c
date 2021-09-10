#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int N;

void *fibonacci(void *arg){
	int *A = (int*)arg;				// cast void* --> int*
	int i;
	
	for(i = 0; i <= N; i++){
		A[i] = A[i-1] + A[i-2]; 
	}
	pthread_exit(NULL);
}

int main(){
	pthread_t child;
	scanf("%d",&N);	// input bilangan fibonacci ke-N
	
	int A[N+2], i;
	A[0] = 0; 
	A[1] = 1; 
	
	//Thread child memproses bilangan fibonacci
	pthread_create(&child, NULL, fibonacci, &A[2]);
	pthread_join(child, NULL);

	//Thread parent mencetak baris fibonacci
	for (i=1; i<N; i++){
		printf("%d, ",A[i]);
	}
	printf("%d\n",A[N]);
	
	return 0;
}