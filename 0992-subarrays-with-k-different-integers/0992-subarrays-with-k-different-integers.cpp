class Solution {
public:
    
    int atmost(vector<int> nums,int k){
         int i=0,res=0;
        unordered_map<int,int> m;
        int s = 0;
        for(int j=0;j<nums.size();j++)
        {
            if(!m[nums[j]]++)
                s++;
            while(k<s)
            {
                m[nums[i]]--;
                
                if(m[nums[i]] == 0)
                    s--;
                i++;
            }
            res+=j-i+1;
        }
        return res;
        
    }
        
        
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};