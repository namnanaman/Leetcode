class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(auto i : nums){
            pq.push(i);
        }
        int x = 0;
        while(!pq.empty() && k != 0){
            x =  pq.top();
            pq.pop();
            k--;
        }
        return x;
    }
};