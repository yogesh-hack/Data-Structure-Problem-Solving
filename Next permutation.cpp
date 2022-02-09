/*A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], 
the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. 
More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, 
then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not 
possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

Input: nums = [1,2,3]
Output: [1,3,2]

Input: nums = [3,2,1]
Output: [1,2,3]
*/

/*Approach 1: Using an algorithm _> T.C -> O(n)

Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
Find the largest index l > k such that nums[k] < nums[l].
Swap nums[k] and nums[l].
Reverse the sub-array nums[k + 1]
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int index1, index2;
        
        // Find the point of change
        for(index1 = n - 2; index1 >= 0; index1--) {
            if(nums[index1] < nums[index1 + 1])
                break;
        }
        
        if(index1 < 0) 
            reverse(nums.begin(), nums.end());
        
        else {
            
            // Find the next number to replace index1. (this no will be just bigger than it )
            // index2 occurs ahead of index1
            for(index2 = n - 1; index2 > index1; index2--) {
                if(nums[index2] > nums[index1])
                    break;
            }
            
            swap(nums[index1], nums[index2]);
            
            // reverse the right of index1 for lexicographically next perm
            reverse(nums.begin() + index1 + 1, nums.end());
        }
        
    }
};

//Approach 2: Brute Force: Generating all permutations: O(n!)

#include <bits/stdc++.h>
using namespace std;

void getPerms(int index, int n, vector<int> &arr, vector<vector<int>> &res) {
    
    if(index == n) {
        res.push_back(arr);
        return;
    }
    
    for(int i = index; i < n; i++) {
        swap(arr[i], arr[index]);
        
        getPerms(index + 1, n, arr, res);               
        
        swap(arr[i], arr[index]);
    }
}

vector<int> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;
    int n = nums.size();
    
    getPerms(0, n, nums, res);
    sort(res.begin(), res.end());

    int index = 0;
    for(int i = 0; i < res.size(); i++) {
        int fullMatch = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(res[i][j] == nums[j]) {
                fullMatch++;
            }
        }
        if(fullMatch == nums.size())
            index = i;
    }

    int requiredPos = index == res.size() - 1 ? 0 : index + 1;

    return res[requiredPos];
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> res = permute(arr);
    for(int val: res)
        cout << val << " ";
    return 0;
}

// 1 2 4 
// 1 4 2 
// 2 1 4 
// 2 4 1 
// 4 1 2 
// 4 2 1 
