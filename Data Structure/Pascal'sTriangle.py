# problem : 118

# Input: numRows = 5
# Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        list1=[]
        for i in range(numRows):
            level=[]
            for j in range(i+1):
                if j==0 or j==i:
                    level.append(1)
                else:
                    level.append(list1[i-1][j-1]+list1[i-1][j])
            list1.append(level)
        return list1
        
