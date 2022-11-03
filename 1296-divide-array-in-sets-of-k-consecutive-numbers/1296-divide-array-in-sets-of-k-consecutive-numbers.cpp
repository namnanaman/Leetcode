class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        if(nums.size()%k) return false;
        
        map<int,int> m;
        
        for(auto i : nums){
            m[i]++;                
        }
        
        while(m.size()){
            int val = m.begin()->first;
            
            for(int card = val;card < val+ k;card++){
                if(m.find(card) == m.end()) return false;
                
                int count = m[card];
                
                if(count == 1) m.erase(card);
                else m[card]--;
            }
            
        }
        return true;
        
    }
};