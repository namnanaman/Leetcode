class Solution {
public:
    int leastInterval(vector<char>& tasks, int f) {
        vector<int>  v(26,0);
        int n =tasks.size();
        for(int i = 0; i < tasks.size();i++){
            v[tasks[i]-'A']++;
        }
        
        sort(v.begin(),v.end());
        
        int maxi = v[25]-1;
        
        int idol_slots = maxi*f;
        
        for(int i = 24;i >= 0;i--){
            idol_slots -= min(maxi,v[i]);
        }
        
        return idol_slots > 0 ? n + idol_slots : n;
    }
};