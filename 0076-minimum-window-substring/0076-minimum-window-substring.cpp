class Solution {
public:
    string minWindow(string s, string t) {
        int ki = INT_MAX;
        int kj = INT_MAX;
        int ans = INT_MAX;
        
        unordered_map<char,int> m1,m2;
        
        for(auto i : t){
            m1[i]++;
        }
        set<char> st;
        int sz = m1.size();
        
        int i = 0;
        
        for(int j =0;j < s.size();j++){
            m2[s[j]]++;
            
            if(m2[s[j]] == m1[s[j]]){
                st.insert(s[j]);
            }
            
            if(m1.find(s[j]) != m1.end()){
                while(m2[s[i]] > m1[s[i]] && st.size() == sz){
                    m2[s[i]]--;
                    i++;
                }
            }
            
            if(st.size() == sz){
                if(j-i+1 < ans){
                    ans = j-i+1;
                    ki = i;
                    kj = j;
                }
            }
            
            
        }
        if(kj == INT_MAX){
            return "";
        }
        return s.substr(ki,kj-ki+1);
        
    }
};