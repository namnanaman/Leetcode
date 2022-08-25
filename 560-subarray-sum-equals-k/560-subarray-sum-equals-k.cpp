class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> PrevSum;
        
        int sum = 0;
        
        
        for(int i = 0;i<n;i++){
            sum += nums[i];
            
            if(sum == k) count+=1;
            
            if(PrevSum.find(sum-k) != PrevSum.end()){
                count += PrevSum[sum-k];
            }
            
            PrevSum[sum]++;
            
        }
        return count;
        
    }
};