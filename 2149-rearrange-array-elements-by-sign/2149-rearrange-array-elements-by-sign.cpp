class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        
        for(int i =0;i < nums.size();i++){
            if(nums[i] > 0) pos.push_back(nums[i]);
            if(nums[i] < 0) neg.push_back(nums[i]);
        }
        int poscnt = 0;
        int negcnt = 0;
        for(int i =0;i < nums.size();i++){
            if(i%2 == 0){
                nums[i] = pos[poscnt++];
            }
            else nums[i] = neg[negcnt++];
            
        }
        return nums;
        
    }
};