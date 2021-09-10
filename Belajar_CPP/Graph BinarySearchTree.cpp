#include <iostream>  
using namespace std; 

void fun1(int arr[], int n, int i) {  
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1   
	int r = 2 * i + 2; // right = 2*i + 2  
	if (l < n && arr[l] > arr[largest])    
		largest = l;    
	if (r < n && arr[r] > arr[largest])    
		largest = r;  
	if (largest != i) {    
		swap(arr[i], arr[largest]);    
		fun1(arr, n, largest);   
	}  
} 

void fun2(int arr[], int n) {   
	int startIdx = (n / 2) - 1;  
	for (int i = startIdx; i >= 0; i--) {    
		fun1(arr, n, i);   
	}  
}

void fun3(int arr[], int& n) {       
	int lastElement = arr[n - 1];       
	arr[0] = lastElement;    	//soal 3  
	n = n - 1;       
	fun1(arr, n, 0);  			//soal 3
}

void printArray(int arr[], int n)  {      
	for (int i = 0; i < n; ++i)          
		cout << arr[i] << " ";      
	cout << "\n";  
} 

int main()  {  
	int arr[] = {20, 16, 11, 2, 4, 5, 1, 6, 10, 13};   
	int n = sizeof(arr) / sizeof(arr[0]);   
	fun2(arr, n);   
	printArray(arr, n);
	fun3(arr, n);   
	printArray(arr, n);
	 
	return 0;  
}