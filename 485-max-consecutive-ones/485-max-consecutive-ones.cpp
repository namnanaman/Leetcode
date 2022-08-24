class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int best = 0;
        
        int curr = 0;
        
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == 1){
                curr+=1;
                best = max(best,curr);
            }
            if(nums[i] == 0){
                best = max(best,curr);
                curr = 0;
            }
        }
        return best;
    }
};