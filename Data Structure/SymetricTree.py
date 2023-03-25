#Problem : 101

# Input: root = [1,2,2,3,4,4,3]
# Output: true

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.isSame(root, root)
    
    def isSame(self, n1, n2):
        if not n1 and not n2:
            return True
        elif not n1 or not n2:
            return False
        
        return n1.val == n2.val and self.isSame(n1.right, n2.left) and self.isSame(n1.left, n2.right)
