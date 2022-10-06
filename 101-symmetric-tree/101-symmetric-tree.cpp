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
    bool cal(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2==NULL){
            return true;
        }
        if(root1&&root2&&root1->val==root2->val){
            return cal(root1->left,root2->right)&&cal(root1->right,root2->left);
        }
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
       return cal(root->left,root->right);
    }
};