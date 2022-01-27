/*Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
Note: Return -1 if you can't reach the end of the array.

Input:
N = 11
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3
Explanation:
First jump from 1st element to 2nd
element with value 3. Now, from here
we jump to 5th element with value 9,
and from here we will jump to last.  */

/*
Following are steps:

1.)if n <= 1, then return 0, because that is the destination
2.)If arr[0] == 0 then return -1 as answer (no jumps are possible)
  Now, Initialize maxrange and steps with arr[0], and jumps with 1 (as 1 jump will be required)
  Now, starting iteration from index 1, the above values are updated as follows:
  First we test whether we have reached the end of the array, in that case we just need to return the jump variable
  if (i == arr.length - 1) return jump;
  Next we update the maxrange. This is equal to the maximum of maxrange and i+arr[i](the number of steps
  we can take from the current position).
  maxrange = max(maxrange,i+arr[i]);
3.)We used up a step to get to the current index, so steps has to be decreased.
  step--;
4.)If no more steps are remaining (i.e. steps=0, then we must have used a jump.
Therefore increase jump. Since we know that it is possible to reach maxrange, we again initialize
the steps to the number of steps to reach maxReach from position i.
.
  if (step == 0) {
      jump++;
      if(i>=maxReach)
        return -1;
      step = maxReach - i;
    }
5.)Print the returned value
*/
#include<bits/stdc++.h>
using namespace std;
int minJumps(int arr[], int n)
   {
       if (n <= 1)
           return 0;
       if (arr[0] == 0)
           return -1;
       int maxReach = arr[0];
       int step = arr[0];
       int jump =1;
       int i=1;
       for (i = 1; i < n; i++)
       {
           if (i == n-1)
               return jump;

           maxReach = max(maxReach, i+arr[i]);
           step--;
           if (step == 0)
           {
               jump++;
               if(i >= maxReach)
                   return -1;
               step = maxReach - i;
           }
       }
       return -1;
   }

int main(){
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;++i){
       cin>>arr[i];
     }
     minJumps(arr,n);
     return 0;
   }
