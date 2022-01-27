/*Move all negative numbers to beginning and positive to end with constant extra space
Difficulty Level : Easy
Last Updated : 09 Jun, 2021
An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.

Examples :

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5  */


#include <bits/stdc++.h>
using namespace std;
void rearrange(int arr[], int n)
{
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			if (i != j)
				swap(arr[i], arr[j]);
			j++;
		}
	}
}
//using simply quicksort partition method
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
}

int main()
{
  int n;
  cin>>n;
	int arr[n]
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
	rearrange(arr, n);
	printArray(arr, n);
	return 0;
}
