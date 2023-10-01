# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        q = []
        
        lis = []
        if root:
            q.append(root)

        while q:
            size = len(q)
            level = []

            for i in range(size):
                rt = q.pop(0)
                level.append(rt.val)
                if rt.left:
                    q.append(rt.left)
                if rt.right:
                    q.append(rt.right)
            lis.append(level)
        return lis

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        lis = self.levelOrder(root)
        l1=[]
        for i in lis:
            l1.append(i[-1])
        return l1