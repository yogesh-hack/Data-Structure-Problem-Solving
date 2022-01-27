/*find Largest sum contiguous Subarray [V. IMP]
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
Example 2:

Input:
N = 4
Arr[] = {-1,-2,-3,-4}
Output:
-1
Explanation:
Max subarray sum is -1
of element (-1)    */

#include<bits/stdc++.h>
using namespace std;
int maxSubarraySum(int arr[], int size)
{
  	int max = 0, max_so_far = INT_MIN;
  	for (int i = 0; i < size; i++) {
  		if (arr[i] <= max + arr[i]) {
  			max += arr[i];
  		}
  		else {
  			max = arr[i];
  		}
  		if (max > max_so_far)
  			max_so_far = max;
  	}
  	return max;
  }

int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;++i){
    cin>>arr[i];
  }
  cout<<"maxSubArraySum is :"<<maxSubarraySum(arr,n);
  return 0;
}


// using dynamic programing....
#include<iostream>
using namespace std;

int maxSubArraySum(int a[], int size)
{
int max_so_far = a[0];
int curr_max = a[0];

for (int i = 1; i < size; i++)
{
		curr_max = max(a[i], curr_max+a[i]);
		max_so_far = max(max_so_far, curr_max);
}
return max_so_far;
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;++i){
    cin>>arr[i];
  }
  cout<<"maxSubArraySum is :"<<maxSubarraySum(arr,n);
  return 0;}
