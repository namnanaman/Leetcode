class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
           map<int,int> m;
        
        for(int i = 0;i < nums.size();i++){
            int newtarget =target -  nums[i];
            if(m.find(newtarget) != m.end()){
                return {i,m[newtarget]};   
            }
            m[nums[i]] = i;
            
        }
        
        
        return {};
    }
};