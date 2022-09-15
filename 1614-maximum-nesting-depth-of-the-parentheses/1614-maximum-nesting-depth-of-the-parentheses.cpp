class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        unordered_map<char,int> m;
        int l = 0;
        for(auto i  : s){
            if(i == '(') cnt++;
            else if(i == ')') cnt--;
            
               l = max(cnt,l);
            
        }
        return l;
        
    }
};