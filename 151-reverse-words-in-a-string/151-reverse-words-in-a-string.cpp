class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = s.size();
        string ans = "";
        
        while(i < n){
            while(i <= n && s[i] == ' ') i++;
            
            if(i == n) return ans;
            int j = i + 1;
            
            while(j < n && s[j] != ' ')j++;
            string k = s.substr(i,j-i);
            if(ans == "") ans = k;
            else ans = k + ' ' + ans;
            i = j + 1;
        }
        return ans;
    }
};