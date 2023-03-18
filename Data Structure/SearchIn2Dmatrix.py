# problem : 74

# Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
# Output: true

# Approach : Binary Search

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # using binary search
        if not matrix or target is None:
            return False
        
        row, col = len(matrix), len(matrix[0])
        low = 0
        high = row * col - 1
        while(low <= high):
            mid = (low + high) // 2
            num = matrix[mid // col][mid % col]
            if num == target:
                return True
            elif num < target:
                low = mid + 1
            else:
                high = mid - 1
        return False
        
