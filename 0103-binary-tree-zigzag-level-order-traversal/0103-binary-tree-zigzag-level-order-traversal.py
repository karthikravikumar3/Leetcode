# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q= []
        lis = []
        if root:
            q.append(root)
        count=-1
        while q:
            size = len(q)
            level=[]
            
            count=count+1
            for i in range(size):
                node = q.pop(0)
                level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if count%2==0:
                lis.append(level)
            else:
                level.reverse()
                lis.append(level)
        return lis

