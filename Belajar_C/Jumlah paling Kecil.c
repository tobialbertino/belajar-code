#include <stdio.h>
#include <math.h>

// source"https://www.geeksforgeeks.org/smallest-sum-contiguous-subarray/"
int smallestSumSubarr(int arr[], int n)
{
    // to store the minimum value that is ending
    // up to the current index
    int max = 1000000;
      // C++ implementation to find the
    // to store the minimum value encountered so far
    int min = 1000000;

    // traverse the array elements
    for (int i=0; i<n; i++)
    {
        // if min_ending_here > 0, then it could not possibly
        // contribute to the minimum sum further
        if (max > 0)
            max = arr[i];

        // else add the value arr[i] to min_ending_here
        else
            max += arr[i];

        // update min_so_far
        if (min> max)

        min = max;
    }

    // required smallest sum contiguous subarray value
    return min;
}


int main(){
    int a[100000];
    int n,i,subarrayterkecil;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("%d\n",smallestSumSubarr(a,n));
}
