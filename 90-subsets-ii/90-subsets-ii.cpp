class Solution {
public:
    void f(vector<int> &nums,vector<vector<int>> &ans,vector<int> &sub,int idx){
        bool isPresent = false;
        
        if(idx >= nums.size()){
            for(auto i : ans){
                if(i == sub){
                    isPresent = true;
                    break;
                }
            }
            if(!isPresent){
                ans.push_back(sub);
            }
            return;
        }
        
        sub.push_back(nums[idx]);
        f(nums,ans,sub,idx+1);
        sub.pop_back();
        f(nums,ans,sub,idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        
        sort(nums.begin(),nums.end());
        f(nums,ans,sub,0);
        
        return ans;
        
        
    }
};