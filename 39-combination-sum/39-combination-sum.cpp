class Solution {
public:
    void f(vector<int>& candidates, int target,int idx,vector<vector<int>> &ans,vector<int> len){
        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(len);
            }
            return;
        }
        
        if(candidates[idx] <= target){
            len.push_back(candidates[idx]);
            f(candidates,target- candidates[idx],idx,ans,len);
            len.pop_back();
        }
        
        f(candidates,target,idx+1,ans,len);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>  ans;
        vector<int> len;
        
        f(candidates,target,0,ans,len);
        return ans;
    }
};