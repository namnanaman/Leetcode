class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ma = nums[0];
        int mi = nums[0];
        
        int best = nums[0];
        
        for(int i = 1;i < nums.size();i++){
            if(nums[i] < 0) swap(ma,mi);
            
            ma  = max(ma*nums[i],nums[i]);
            mi = min(mi*nums[i],nums[i]);
            
            best = max(best,ma);
            
        }
        
        return best;
    }
};