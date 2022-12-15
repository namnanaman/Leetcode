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
    vector<int> rightSideView(TreeNode* root) {
    
        vector<int> x;
        
        if(root == NULL){
            return x;
        }
            queue<TreeNode*> q;
        
        
        
        q.push(root);
        while(!q.empty()){
         
            int s = q.size();
            vector<int> ans;
            for(int i = 0;i <s;i++ ){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left) q.push(node->left);
                
                if(node->right) q.push(node->right);
                
                ans.push_back(node->val);
                
            }
            
            x.push_back(ans[ans.size()-1]);
            
            
        }
        return x;
    }
};