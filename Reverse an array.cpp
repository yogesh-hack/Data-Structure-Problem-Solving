/*Write a program to reverse an array or string

Given an array (or string), the task is to reverse the array/string.
Examples :

Input  : arr[] = {1, 2, 3}
Output : arr[] = {3, 2, 1}

Input :  arr[] = {4, 5, 1, 2}
Output : arr[] = {2, 1, 5, 4}
*/

#include <bits/stdc++.h>
using namespace std;
void rvereseArray(int arr[], int start, int end)
{
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main()
{
  int N;
  cin>>N;
	int arr[N];
  for(int i=0;i<N;++i){
    cin>>arr[i];
  }
  cout<<<"original array:"<<endl;
	printArray(arr, n);
	rvereseArray(arr, 0, n-1);
	cout << "Reversed array is" << endl;
	printArray(arr, n);
	return 0;
}
