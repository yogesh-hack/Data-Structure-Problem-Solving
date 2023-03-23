# problem : 94

# Input: root = [1,null,2,3]
# Output: [1,3,2]

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
     def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
       output, stack = [], []
       while stack or root:
           if root:
               stack.append(root)
               root = root.left
           
           else:
               node = stack.pop()
               output.append(node.val)
               root = node.right
               
       return output
