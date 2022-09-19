class Solution {
public:
    int alpha(vector<int> &beauty){
        int low = 1e9;
        int high = -1e9;
        
        for(int  i : beauty){
            if(i >=1){
                low = min(low,i);
            }
            
            high = max(high,i);
        }
        return high-low;
    }
    int beautySum(string s) {
        
        int ans = 0;
        for(int i =0;i < s.size();i++){
            vector<int> beauty(26,0);
            for(int j = i;j < s.size();j++){
                beauty[s[j] - 'a']++;
                ans += alpha(beauty);
                
                
            }
        }
        return ans;
        
        
    }
};