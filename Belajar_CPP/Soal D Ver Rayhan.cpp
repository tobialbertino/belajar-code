#include<iostream>
#include<algorithm>
using namespace std;

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
}

int main()
{
	int num,arr[7],key=-1;
	cin>>num;
	int i=0;
	while(num>0){
		arr[i++]=num%10;
		num/=10;
	}
	int n = i;
	//cout<<n<<endl;
	reverse(arr, arr+n);
	for(int i = n-1; i>=0; i--){
		for(int j=i; j>=0; j--){
			if(arr[j]<arr[i]){
				swap(arr[j],arr[i]);
				key = j+1;
				break;
			}
		}
		if(key > -1) break;
	}
	if(key == -1){
		cout<<0<<endl;
	}else{
		sort(arr+key, arr+n);
		print(arr, n);
		cout<<endl;
	}
}