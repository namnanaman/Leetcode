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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        
        TreeNode* left = root;
        TreeNode* right = root;
        
        int ll = 0;
        int rr = 0;
        
        while(left){
            left = left->left;
            ll++;
        }
        while(right){
            right = right->right;
        }
        if(ll == rr) return 2*ll -1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};