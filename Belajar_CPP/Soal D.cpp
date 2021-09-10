#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

void printNum(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
}

int main() 
{
	int num, arr[7], key = -1;
    int i, n, j;
	cin >> num;
    i = 0;
    while (num > 0){
        arr[i++] = num % 10;
        num /= 10;
    }
    n = i;
    //cout << n ;
    reverse (arr, arr + n);
    //printNum(arr, n);

    for (i = n-1; i>=0; i--)
    {
        for(j = i; j>=0; j--)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j], arr[i]);
                key = 1;
                break;
            }
        }
        if (key != -1)
            break;
    }
    if (key == -1)
        cout << 0 << endl;
    else {
        printNum(arr, n);
        cout << endl;
    }

}
