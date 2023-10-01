# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        self.count=0
        def dfs(curr: Optional[TreeNode]):
            if not curr:
                return
            self.count+=1
            if curr.left:
                dfs(curr.left)
            if curr.right:
                dfs(curr.right)
        dfs(root)
        return self.count