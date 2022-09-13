class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod=  1;
        vector<int> left;
        for(int i  =0; i < n;i++){
            prod *= nums[i];
            left.push_back(prod);
        }
        prod = 1;
        vector<int> right;
        for(int  i = n-1;i >= 0;i--){
            prod *= nums[i];
            right.push_back(prod);
        }
        reverse(right.begin(),right.end());
        
        
        vector<int> ans;
        ans.push_back(right[1]);
        for(int  i = 1;i < n-1;i++){
            ans.push_back(left[i-1] *right[i+1]);
        }
        ans.push_back(left[n-2]);
        return ans;
        
    }
};