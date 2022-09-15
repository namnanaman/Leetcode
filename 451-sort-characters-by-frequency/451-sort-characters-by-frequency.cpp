class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> un;
        
        for(auto i : s){
            un[i]++;
        }
        
        map<int,string> m;
        
        for(auto  i : un){
            char c = i.first;
            int n = i.second;
            
            m[n] += string(n,c);
        }
        
        string ans = "";
        
        for(auto i = m.rbegin(); i!= m.rend();i++){
            ans += i->second;
        }
        return ans;
        
    }
};