/*Given an array arr[] and an integer K where K is smaller than size of array,
the task is to find the Kth smallest element in the given array. It is given that all
array elements are distinct.

Example 1:
Input:                                Output
N = 6                                  7
arr[] = 7 10 4 3 20 15
K = 3

Explanation :
3rd smallest element in the given
array is 7.

Example 2:
Input:                                 Output
N = 5                                  15
arr[] = 7 10 4 20 15
K = 4

Explanation :
4th smallest element in the given
array is 15.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
Constraints:
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N  */

#include<bits/stdc++.h>
using namespace std;
int kthminimum(int arr[], int l, int r, int k) {
    sort(arr,arr+r+1);
    return arr[k-1];
}
int kthmaximum(int arr[n], int l,int r, int k){
  sort(arr,arr+r+1);
  return arr[r-1];
}

int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int ns;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthminimum(a, 0, n-1, k)<<endl;
        cout<<kthmaximum(a, 0, n-1, k);
    }
    return 0;
}
