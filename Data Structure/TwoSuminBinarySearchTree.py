# Problem : 653

# Input: root = [5,3,6,2,4,null,7], k = 9
# Output: true

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        if not root:
            return False

        visit=set()
        q=[root]
        for i in q:
            if (k-i.val) in visit:
                return True
            visit.add(i.val)
            if i.left:
                q.append((i.left))
            if i.right:
                q.append(i.right)
        return False
