# problem : 144

# Input: root = [1,null,2,3]
# Output: [1,2,3]


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
     #solution1: recursion  | Time: O(n) | Space: O(n)
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        def preorder(root):
            if not root: return 
            res.append(root.val)
            preorder(root.left)
            preorder(root.right)
        preorder(root)
        return res
        #Solution2: ierator | Time: O(n) | Space: O(n)
        stack = [root]
        res = []
        while stack:
            node = stack.pop()
            if node: 
                res.append(node.val)
                stack.append(node.right)
                stack.append(node.left)
        return res

  
 # ------------------------------------------------------------------------------- 
      
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
     #Solution2: ierator | Time: O(n) | Space: O(n)
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        stack = [root]
        res = []
        while stack:
            node = stack.pop()
            if node: 
                res.append(node.val)
                stack.append(node.right)
                stack.append(node.left)
        return res

            



