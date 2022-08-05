class Solution {
public:
    
    void f(vector<int>&candidates,int target,int idx,vector<vector<int>> &ans,vector<int> &len){
        if(target == 0){
            ans.push_back(len);
            return;
        }
        
        for(int i = idx; i < candidates.size();i++){
            if(candidates[i] > target) return;
            
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            
            len.push_back(candidates[i]);
            f(candidates,target - candidates[i],i+1,ans,len);
            len.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>>  ans;
        
        vector<int> len;
        
        f(candidates,target,0,ans,len);
        
        return ans;
        
        
    }
};