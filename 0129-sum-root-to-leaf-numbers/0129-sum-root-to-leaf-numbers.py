# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        def dfs(curr:Optional[TreeNode], local: int):
            if not curr.left and not curr.right:
                self.ans +=local*10+curr.val
                return
            if curr.left:
                dfs(curr.left,local*10+curr.val)
            if curr.right:
                dfs(curr.right,local*10+curr.val)
        dfs(root,0)
        return self.ans