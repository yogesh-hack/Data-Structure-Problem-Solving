/*Count pairs with given sum 
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:

Input:
N = 4, X = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1.


FOLLOWING STEP ARE :
Use a hash map to solve :
->  Create a map to store frequency of each number in the array. (Single traversal is required)
->  For every element check if it can be combined with any other element (other than itself!) to give the desired sum. 
    Increment the counter accordingly. After completion of second traversal, we’d have twice the required value stored in counter 
    because every pair is counted two times. 
->  Also take care of pairs with duplicate elements like (2,2) when K =4.
*/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;
int getPairsCount(int arr[], int n, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) 
        m[arr[i]]++;

    int twice_count = 0;
    for (int i = 0; i < n; i++) {
        twice_count += m[k - arr[i]];
        if (k - arr[i] == arr[i]) twice_count--;
    }
    return twice_count / 2;
}
  
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getPairsCount(arr, n, k);
        cout << ans << "\n";
    }    
    return 0;
} 
