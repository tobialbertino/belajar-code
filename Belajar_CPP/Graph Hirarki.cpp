// numbering starting from 0 to n-1.
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

char tree[10];

int root(char key) {  
	if(tree[0] != '\0')  
		cout << "Tree already had root";  
	else 
 		tree[0] = key;  
 	return 0; 
}

int set_left(char key, int parent) {  
	if(tree[parent] == '\0')  
  		cout << "\nCan't set child at" 
   		<< (parent * 2) + 1  
   		<< " , no parent found";  
	else 
		tree[(parent * 2) + 1] = key;  
	return 0; 
}

int set_right(char key, int parent) {  
	if(tree[parent] == '\0')  
		cout << "\nCan't set child at" 
		<< (parent * 2) + 2				//soal 3
		<< " , no parent found";  
	else 
		tree[(parent * 2) + 2] = key;  	//soal 3
	return 0; 
}  

int print_tree() {  
	cout << "\n";  
	for(int i = 0; i < 10; i++) {  
		if(tree[i] != '\0')  
			cout << tree[i];  
		else 
			cout << "-"; 
	}  
	return 0;
}

int main() {  
	root('T');   
	set_left('V',0);   
	set_right('S', 0);   
	set_left('W', 1);   
	set_right('P', 1); 
	set_left('B', 2);   
	set_right('Q', 2);   
	print_tree();   
	return 0;  
} 
