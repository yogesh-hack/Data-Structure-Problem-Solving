# problem : 53
  
# Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
# Output: 6
# Explanation: The subarray [4,-1,2,1] has the largest sum 6.


# BruteForce solution code
class Solution:
    def maxSubArray(self, nums):
        ans = -inf
        for i in range(len(nums)):
            cur_sum = 0
            for j in range(i, len(nums)):
                cur_sum += nums[j]
                ans = max(ans, cur_sum)
        return ans
      
#  using Kadane Algorithms code
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum = 0
        temp = -inf
        for i in range(len(nums)):
            sum = sum + nums[i]
            if(temp < sum):
                temp = sum
            if(sum < 0):
                sum = 0
        return temp

