/*Common elements 

Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;  
vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
  int i=0, j=0, k=0;
  set<int>s;

  while(i<n1 && j<n2 && k<n3){
      if(A[i] == B[j] && B[j] == C[k]){
          s.insert(A[i]);
          i++;
          j++;
          k++;
      }
      else if(A[i] < B[j])
          i++;

      else if(B[j]<C[k])
          j++;

      else
          k++;
  }
  vector<int> res;

  for(auto el: s)
      res.push_back(el);

  return res;
}


int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        vector <int> res = commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
