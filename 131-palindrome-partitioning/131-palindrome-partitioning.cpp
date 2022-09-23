class Solution {
public:
    
    
    bool isPalindrome(int start,int end,string &s){
        
        while(start <= end){
            
            if(s[start++] != s[end--]) return false;
            
        }
        
        return true;
    }
    
    void f(string &s,vector<vector<string>> &ans,vector<string> &curr,int idx){
        if(idx == s.size()) //base condition
        {
            ans.push_back(curr);
            return;
        }
        
        for(int end = idx; end < s.size();end++){
            if(isPalindrome(idx,end,s)){
                curr.push_back(s.substr(idx,end-idx+1));
                
                f(s,ans,curr,end+1);
                curr.pop_back();
                
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        
        f(s,ans,curr,0);
        
        return ans;
    }
};