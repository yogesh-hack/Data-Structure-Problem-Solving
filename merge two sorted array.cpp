/*Merge Without Extra Space 

Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. 
Merge the two arrays into one sorted array in non-decreasing order without using any extra space.

Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}

Output: 0 1 2 3 5 6 7 8 9
Explanation: Since you can't use any 
extra space, modify the given arrays
to form 
arr1[] = {0, 1, 2, 3}
arr2[] = {5, 6, 7, 8, 9}

Following are steps :-

->  Maintain 2 iterators i, j for 2 arrays. 
->  Calculate gap
->  First iterate the first array, and check for elements at index i and i + gap, and swap if second is smaller.
->  When i + gap will cross the last index of first array, the control will move on to second array.
->  So now iterate, for i in first array, and j in second array, till one stops.
->  we need to consider the case, when gap comes more than size of first array, at start of iteration.
->  Then the iteration in second array should start from index gap - n (size of arr1), and not 0
->  Also, at end of iteration, when one of the iterators come to end, there are 2 cases
->  if j ends for second array, then the iteration ends but, if i ends for first array, and second array is still 
    left for iteration, then we need to iterate for second array, 
    and check for elements at j and j + gap, and swap accordingly
    
But there are 2 more cases, to think about in this solution. Try yourself. Think Hard.

*/

#include <bits/stdc++.h>
using namespace std;
int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2);
}
void merge(int arr1[], int arr2[], int n, int m) {
    int i, j, gap = n + m;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap]) swap(arr1[i], arr1[i + gap]);

        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
            if (arr1[i] > arr2[j]) swap(arr1[i], arr2[j]);

        if (j < m) {

            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap]) swap(arr2[j], arr2[j + gap]);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} 
