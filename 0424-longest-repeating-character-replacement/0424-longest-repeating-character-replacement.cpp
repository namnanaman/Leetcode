class Solution {
public:
    int characterReplacement(string s, int k) {
        int most = 0;
        int start = 0;
        int ans = 0;
        
        vector<int> freq(26);
        
        for(int end = 0;end < s.size();end++){
             freq[s[end] - 'A']++;
            most = max(most,freq[s[end] - 'A']);
            
            int letterToChange = (end-start + 1) - most;
            
            if(letterToChange > k){
                freq[s[start] - 'A']--;
                start++;
            }
            
            ans = max(ans,end-start + 1);
            
            
            
        }
        return ans;
        
        
        
    }
};