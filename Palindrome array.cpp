/*Palindromic Array 
Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 
if all the elements of the Array are palindrome otherwise it will return 0.

Example:
Input:
2
5
111 222 333 444 555
3
121 131 20

Output:
1
0

Explanation:
For First test case.
n=5;
A[0] = 111    which is a palindrome number.
A[1] = 222    which is a palindrome number.
A[2] = 333    which is a palindrome number.
A[3] = 444    which is a palindrome number.
A[4] = 555    which is a palindrome number.
As all numbers are palindrome so This will return 1.*/


#include<iostream>
#include<string.h>
using namespace std;

int PalinArray(int arr[], int n){
 int count=0;
 for(int i=0;i<n;i++){
     int rev_num=0;
     int num=arr[i];
     while(num>0){
         rev_num=rev_num*10 + num%10;
         num = num/10;
     }
     if(rev_num==arr[i]){
         count++;
     }
 }
 if(count==n){
     return 1;
 }
 return 0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
} 
