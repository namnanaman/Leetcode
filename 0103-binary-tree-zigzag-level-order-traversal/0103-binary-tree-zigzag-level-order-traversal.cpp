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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == NULL) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        
        
        q.push(root);
        int cnt = 0;
        
        while(!q.empty()){
            int s = q.size();
            vector<int> x;
            for(int i = 0;i < s;i++){
                TreeNode* t = q.front();
                q.pop();
                
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                
                x.push_back(t->val);
            }
            
            if(cnt%2){
                reverse(x.begin(),x.end());
            }
            cnt++;
            ans.push_back(x);
        }
        
        
        return ans;
    }
};