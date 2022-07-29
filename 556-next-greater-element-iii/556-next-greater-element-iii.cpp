class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        
        if(!NextPermutation(s)) return -1;
        
        auto number = stoll(s);
        
        return (number > INT_MAX || number <= n) ? -1 : number;
    }
    
    bool NextPermutation(string &s){
        if(!s.size()) return 0;
        int n = s.size();
        //int i = s.size()-1;
        int idx = -1;
        
        for(int i =n-1; i>= 1;i-- ){
            if(s[i]  > s[i-1]){
                idx = i;
                break;
            }
        }
        if(idx == -1) {
            return false;
        }else{
            int prev = idx;
            for(int i = idx + 1; i < n;i++){
                if(s[i] > s[idx-1] && s[i] <= s[prev]){
                    prev = i;
                }
            }
            swap(s[idx-1],s[prev]);
            reverse(s.begin()+idx,s.end());
        }
        
        return true;
        
        
    }
};