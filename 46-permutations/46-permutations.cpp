class Solution {
public:
    void f(vector<int> &nums,vector<vector<int>> &ans,vector<int>&vis,vector<int> &one){
        
        if(one.size() == nums.size()){
            ans.push_back(one);
            return;
        }
        
        for(int i =0; i < nums.size();i++){
            if(vis[i] == 0){
                vis[i] = 1;
                one.push_back(nums[i]);
                f(nums,ans,vis,one);
                vis[i] = 0;
                one.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> one;
        int n = nums.size();
        
        vector<int> vis(n,0);
        f(nums,ans,vis,one);
            return ans;
    }
};