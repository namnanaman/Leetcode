class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool> (n));
        string ans = "";
        int count = 0;
        //single char 
        for(int i = 0 ; i < n;i++ ) {
            dp[i][i] = true;
            count = max(count,1);
            ans = s.substr(i,i+1);
        } 
        
        for(int i = 0; i < n-1;i++ ){
            dp[i][i+1] = s[i] == s[i+1];
            if(dp[i][i+1] == true) {
                if(count < 2){
                    count = 2;
                    ans = s.substr(i,2);
                }
            }
        }
        
        for(int len = 3; len <= n; len++){
            for(int i = 0,j = i+len-1; j < n;i++,j++){
                dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
                if(dp[i][j] == true) {
                    if(count < j-i+1){
                        count = j-i+1;
                        ans = s.substr(i,j-i+1);
                    }
                    
                }
            }
        }
        
        return ans;
        
        
        
    }
};