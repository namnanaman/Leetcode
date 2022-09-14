class Solution {
public:
    bool rotateString(string s, string t) {
        int len = t.size();
        int len1 = s.size();
        if(len != len1) return false;
        while(len--){
            if(s == t) return true;
            s = s.substr(1) + s[0];
        }
        return false;
        
    }
};