class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while(k > nums.size()) k-=nums.size();
        if(k == nums.size()) return;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};