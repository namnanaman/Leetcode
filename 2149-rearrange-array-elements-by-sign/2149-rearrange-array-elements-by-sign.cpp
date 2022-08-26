class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int poscnt = 0;
        int negcnt = 1;
        
        for(int i =0;i < nums.size();i++){
            if(nums[i] > 0){
                ans[poscnt] = nums[i];
                poscnt +=2;
            }else {
                ans[negcnt] = nums[i];
                negcnt += 2;
            }    
        }
        return ans;
        
        
//         vector<int> pos,neg;
        
//         for(int i =0;i < nums.size();i++){
//             if(nums[i] > 0) pos.push_back(nums[i]);
//             if(nums[i] < 0) neg.push_back(nums[i]);
//         }
//         int poscnt = 0;
//         int negcnt = 0;
//         for(int i =0;i < nums.size();i++){
//             if(i%2 == 0){
//                 nums[i] = pos[poscnt++];
//             }
//             else nums[i] = neg[negcnt++];
            
//         }
//         return nums;
        
    }
};