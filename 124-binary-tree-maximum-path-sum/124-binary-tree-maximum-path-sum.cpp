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
    int f(TreeNode* root,int &maxi){
        if(!root) return 0;
        
        int lmax = max(0,f(root->left,maxi));
        int rmax = max(0,f(root->right,maxi));
        
        maxi = max(maxi,root->val + rmax + lmax);
        
        return root->val + max(lmax,rmax);
        
        
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = -1e9;
        
        if(!root) return 0;
        
        int x = f(root,maxi);
        
        return maxi;
        
    }
};