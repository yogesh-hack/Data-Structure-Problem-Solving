# problem : 145

# Input: root = [1,null,2,3]
# Output: [3,2,1]

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        #solution1: recursion  | Time: O(n) | Space: O(n)
        res = []
        def postorder(root):
            if not root: return 
            postorder(root.left)
            postorder(root.right)
            res.append(root.val)
        postorder(root)
        return res

        #Solution2: ierator | Time: O(n) | Space: O(n)
        stack = [root]
        res = []
        while stack:
            node = stack.pop()
            if node: 
                res.append(node.val)
                stack.append(node.left)
                stack.append(node.right)
        return res[::-1]
