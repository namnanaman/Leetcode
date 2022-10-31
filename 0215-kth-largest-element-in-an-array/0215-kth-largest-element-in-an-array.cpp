class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        
        for(auto i  : nums){
            q.push(i);
        }
        
        int x;
        
        while(k){
            x = q.top();
            k--;
            q.pop();
        }
        return x;
        
    }
};