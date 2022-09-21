class Solution {
public:
    void f(vector<int> &nums,vector<vector<int>> &ans,vector<int> &sub,int idx){
        if(idx == nums.size()){
            ans.push_back(sub);
            return;
        }
        
        sub.push_back(nums[idx]);
        f(nums,ans,sub,idx+1);
        sub.pop_back();
        f(nums,ans,sub,idx+1);
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        
        f(nums,ans,sub,0);
        return ans;
    }
};