class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0,j=0,sum = 0,len = 1e9;
        
        while(j < nums.size()){
            sum += nums[j++];
            
            while(sum >= target){
                len = min(len,j-i);
                sum -= nums[i++];
            }
        }
        
        return len == 1e9 ? 0 : len;
    }
};