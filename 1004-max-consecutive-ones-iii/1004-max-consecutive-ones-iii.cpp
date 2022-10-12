class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero_count = 0;
        int start = 0;
        int res = 0;
        
        for(int end = 0;end < nums.size();end++){
            if(nums[end] == 0) zero_count++;
            
            while(zero_count > k){
                if(nums[start] == 0){
                    zero_count--;
                    
                }
                start++;
            }
            res = max(res,end-start+1);
        }
        return res;
    }
};