/*Given an array of integers nums containing n + 1 integers
where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
*/
#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(int i=1;i<nums.size();++i){
        if(nums[i]==nums[i-1]){
            return nums[i];
        }
    }
     return -1;

}
//------------------0(NlongN)----------------------

int findDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (auto &num : nums) {
        if (seen.count(num))
            return num;
        seen.insert(num);
    }
    return -1;
}
 //----------------O(N)---------------------------

int findDuplicate(vector<int>& nums) {
        int duplicate = -1;
        for (int i = 0; i < nums.size(); i++) {
            int cur = abs(nums[i]);
            if (nums[cur] < 0) {
                duplicate = cur;
                break;
            }
            nums[cur] *= -1;
        }
        for (auto& num : nums)
            num = abs(num);

        return duplicate;
    }
//---------------0(N)-------------------------------

int main(){
    int n;
    int vector<int> nums;
    for(int i=0;i<n;++i){
        cin<<x;
        nums.push_back(x);
    }
    cout<<findDuplicate(nums);
}
