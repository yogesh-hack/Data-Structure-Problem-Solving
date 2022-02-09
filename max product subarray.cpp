/*Maximum Product Subarray 

Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum 
product subarray.

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is [6, -3, -10] which gives product as 180.

Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product
is [2, 3, 4, 5] which gives product as 120.*/

//The question is similar to Maximum Subarray Sum 
//Following step are :->
 /*   -> We will keep 2 variables, one that will store maximum positive value - MAXI and one with minimum negative value - MINI.
      -> We will keep sure that MAXI, is always greater than equal to 1 and MINI is always less than equal to 1
      -> Now there are 3 cases:
             *  if arr[i] > 0, then MAXI is MAXI*arr[i], and MINI is min(MIN*arr[i], 1)
             *  if arr[i] == 0, then we need to see for another subarray, and make MAXI = MINI = 1
             *  if arr[i]<0, then MAXI becomes max(MINI*arr[i],1) and MINI becomes MAXI* arr[i]
      -> For every iteration MAXI stores the maximum value so far, so keep another variable OVERALLMAX to store max of all MAXIs.
      -> Print OVERALLMAX.*/




// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> arr, int n) {
  long long minVal = arr[0];
  long long maxVal = arr[0];
  long long maxProduct = arr[0];

  for (int i = 1; i < n; i++) {      
      if (arr[i] < 0) swap(maxVal, minVal);
      maxVal = max((long long)arr[i], maxVal * arr[i]);
      minVal = min((long long)arr[i], minVal * arr[i]);
      maxProduct = max(maxProduct, maxVal);
  }

  return maxProduct;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
