//Find the Union and Intersection of the two sorted arrays.
/*Given two arrays a[] and b[] of size n and m respectively.

Input:
5 3
1 2 3 4 5
1 2 3
Output:
5
Explanation:
1, 2, 3, 4 and 5 are the
elements which comes in the union set
of both arrays. So count is 5. */


#include <bits/stdc++.h>
using namespace std;
void printUnion(int arr1[], int arr2[], int n1, int n2)
{
	set<int> hs;
	for (int i = 0; i < n1; i++)
		hs.insert(arr1[i]);

	for (int i = 0; i < n2; i++)
		hs.insert(arr2[i]);

	for (auto it = hs.begin(); it != hs.end(); it++)
		cout << *it << " ";
	cout << endl;
}

void printIntersection(int arr1[], int arr2[], int n1,int n2)
{
	set<int> hs;
	for (int i = 0; i < n1; i++)
		hs.insert(arr1[i]);

	for (int i = 0; i < n2; i++)
		if (hs.find(arr2[i]) != hs.end())
			cout << arr2[i] << " ";
}

int main()
{
  int n1, n2;
 	    cin>>n1>>n2;
 	    int arr1[n1], arr2[n2];
 	    for(int i = 0;i<n1;i++)
 	       cin >> arr1[i];

 	    for(int i = 0;i<n2;i++)
 	       cin >> arr2[i];
	printUnion(arr1, arr2, n1, n2);
	printIntersection(arr1, arr2, n1, n2);
 return 0;
}
