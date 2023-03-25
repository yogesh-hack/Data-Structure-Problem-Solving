# Problem : 226

# Input: root = [4,2,7,1,3,6,9]
# Output: [4,7,2,9,6,3,1]

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def firstPass(curr = root):
            if curr != None:
                curr.left, curr.right = curr.right, curr.left
                firstPass(curr.left)
                firstPass(curr.right)
            return
        firstPass()
        return root
        
