// You are given a sorted array consisting of only integers where every element appears exactly twice, 
// except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            // count each element in array
            hash[nums[i]]++;
        }

        for(int i=0;i<nums.size();i++){
            if(hash[nums[i]] == 1){
                return nums[i];
            }
        }
        return -1;
    }
};
