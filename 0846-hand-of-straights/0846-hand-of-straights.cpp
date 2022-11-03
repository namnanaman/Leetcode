class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;
        
        map<int,int> m;
        
        for(auto i : hand){
            m[i]++;   
        }
        
        while(m.size()){
            int val = m.begin()->first;
        
            for(int card = val;card < val + groupSize;card++){
                if(m.find(card) == m.end()){
                    return false;
                }
                int count = m[card];
                if(count == 1) m.erase(card);
                else m[card]--;
            }
            
            
        }
        return true;
        
        
        
        
    }
};