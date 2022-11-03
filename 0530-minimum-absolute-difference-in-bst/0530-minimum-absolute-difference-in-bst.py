# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: Optional[TreeNode],l: List[int]):
        if root:
            l.append(root.val)
            self.dfs(root.left,l)
            self.dfs(root.right,l)
        else:
            return
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        l=[]
        self.dfs(root,l)
        l.sort()
        diff=1000000000
        for i in range(len(l)-1):
            if diff>abs(l[i]-l[i+1]):
                diff= abs(l[i]-l[i+1])
        return diff;