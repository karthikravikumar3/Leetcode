# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        li = []
        st = []
        lq=[]
        if root:
            st.append(root)
        while st:
            level = []
            for i in range(len(st)):
                node = st.pop(0)
                level.append(node.val)
                if node.right:
                    st.append(node.right)
                if node.left:
                    st.append(node.left)
            li.append(level)
        
        #print(li)
        
        li = [row[::-1] for row in li]
        return li[::-1]