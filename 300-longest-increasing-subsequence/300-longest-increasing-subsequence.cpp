class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return f(-1,0,nums,dp);
    }
    
    int f(int prev,int curr,vector<int> &nums,vector<vector<int>> &dp){
        if(curr == nums.size()){
            return 0;
        }
        if(prev != -1 && dp[prev][curr]!=-1){
            return dp[prev][curr];
        }
        
        int first = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            first = 1 + f(curr,curr+1,nums,dp);
        }
        int second = f(prev,curr+1,nums,dp);
        
        if(prev != -1){
            return dp[prev][curr] = max(first,second);
        }else return max(first,second);
        
        
        
        return max(first,second);
    }
};