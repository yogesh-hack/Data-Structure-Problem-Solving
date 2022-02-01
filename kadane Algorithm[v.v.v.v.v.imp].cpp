/*Kadane's Algorithm
Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) 
which has the maximum sum and return its sum.


Example 1:

Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which
is a contiguous subarray.
*/

//Following step are:
//  1.Updating max sum till current index.
//  2.Storing max sum so far by choosing maximum between max
//  3.sum so far and max till current index.
//  4.If max sum at current index is negative, we do not need to add
//  5.it to result so we update it to zero.


#include<bits/stdc++.h>
using namespace std;
long long maxSubarraySum(int arr[], int n){
    long long maxh = 0, maxf = a[0];
    for(int i=0;i<n;i++)
        {
            maxh+=a[i];
            if(maxf<maxh)
            maxf=maxh;
            if(maxh<0)
                maxh=0;
        }
        return maxf;
}

int main()
{
    int t,n;

    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout <<maxSubarraySum(a, n) << endl;
    }
}
