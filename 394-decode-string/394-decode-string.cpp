class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return helper(pos, s);
    }
    
    string helper(int& pos, string s) {
        int num = 0;
        string word = "";
        
        for(;pos<s.size();pos++){
            int curr = s[pos];
            if(curr == '['){
                string currWord = helper(++pos,s);
                for(;num > 0; num--) word += currWord;
            }else if(curr >= '0' && curr <= '9'){
                num = num*10 + curr - '0';
            }
            else if(curr == ']'){
                return word;
            }
            else{
                word += curr;
            }
            
        }
        return word;
    }
};