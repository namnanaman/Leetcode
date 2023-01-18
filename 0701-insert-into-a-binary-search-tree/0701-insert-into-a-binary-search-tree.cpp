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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* xd = new TreeNode (val);
            return xd;
            
        }
        TreeNode * curr = root;
        
        while(curr){
            
            if(val > curr->val){
                if(curr->right == NULL){
                    TreeNode* xd = new TreeNode (val);
                   
                    curr->right = xd;
                    break;
                }
                curr = curr->right;
            }else{
                if(curr->left == NULL){
                    TreeNode* xd = new TreeNode (val);
                  
                    curr->left = xd;
                    break;
                }
                curr = curr->left;
            }
        }
        return root;
    }
};