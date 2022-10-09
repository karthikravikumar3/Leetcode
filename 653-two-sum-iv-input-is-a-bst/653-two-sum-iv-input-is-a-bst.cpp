/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    set<int> st;
    bool dfs(TreeNode* root,int k){
        if(root==NULL){
            return false;
        }
        
       
        if(st.find(k-(root->val))!=st.end()){
            
            cout<<k-(root->val)<<"-"<<*st.find(k-(root->val));
            cout<<"yo";
             st.insert(root->val);
            return true;
        }else{
             st.insert(root->val);
            return dfs(root->left,k)||dfs(root->right,k);
            return false;
        }
        
    }
    bool findTarget(TreeNode* root, int k) {
        if(root->left==NULL && root->right==NULL && root->val!=k){
            return false;
        }
        return dfs(root,k);
        
    }
};