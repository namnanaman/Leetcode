class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        
        for(int i : nums){
            m[i]++;
        }
        priority_queue<pair<int,int>> q;
        
        for(auto i : m){
            q.push(make_pair(i.second,i.first));
        }
        vector<int> ans;
        while(k && q.size()){
            ans.push_back(q.top().second);
            q.pop();
            k--;
        }
        return ans;
    }
};