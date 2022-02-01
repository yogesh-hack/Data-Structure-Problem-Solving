// Sort the array without using any sorting algo
/*Given an array of size N containing only 0s, 1s, and 2s; sort the array
in ascending order.

Input:
N = 5
arr[]= {0 2 1 2 0}

Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated
into ascending order. */

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void sort012(int a[], int n)
{
    int low = 0, high = n-1, mid = 0;
    while(mid <= high){
        if(a[mid]==0)
            swap(a[mid++], a[low++]);
        else if(a[mid]==1)
             mid++;
        else
            swap(a[mid], a[high--]);
    }
}

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }
        cout << endl;
    }
    return 0;
}
