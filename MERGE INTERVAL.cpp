/*Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.


Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

APPROACH :-  Sorting 
->  First, we sort the list as described. Then, we insert the first interval into our merged list and 
    continue considering each interval in turn as follows: 
    ->  If the current interval begins after the previous interval ends, then they do not overlap.
    ->  we can append the current interval to merged. 
    ->  Otherwise, they do overlap, and we merge them by updating the end of the previous interval 
        if it is less than the end of the current interval.
        
*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    for (auto interval : intervals) {
        // if the list of merged intervals is empty or if the current
        // interval does not overlap with the previous, simply append it.
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        }
        // otherwise, there is overlap, so we merge the current and previous
        // intervals.
        else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged;
}

  
