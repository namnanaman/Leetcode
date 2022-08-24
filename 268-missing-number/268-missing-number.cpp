class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>  ans(n+1,0);
        
        for(auto i : nums){
            ans[i]++;
        }
        
        for(int i = 0; i < ans.size();i++){
            if(ans[i] == 0){
                return i;
            }
        }
        return -1;
    }
};