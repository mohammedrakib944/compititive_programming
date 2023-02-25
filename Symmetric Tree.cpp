https://leetcode.com/problems/symmetric-tree/description/

class Solution {
    bool isSem(TreeNode* L, TreeNode *R){
        if(L == NULL && R == NULL)
            return true;
        if(L == NULL || R == NULL){
            return false;
        }
        if(L->val != R->val)
            return false;
        return isSem(L->left, R->right) && isSem(L->right, R->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSem(root->left, root->right);    
    }
};