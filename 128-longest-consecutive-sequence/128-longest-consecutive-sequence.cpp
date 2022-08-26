class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m(nums.begin(),nums.end());
        
        int maxStreak = 0;
        
        for(int i : nums){
            if(!m.count(i-1)){
                int streak = 1;
                int curr = i;
                while(m.count(curr+1)){
                    streak+=1;
                    curr+=1;
                }
                maxStreak = max(streak,maxStreak);
            }
        }
        return maxStreak;
        
        
    }
};