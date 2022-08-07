class Solution {
public:
    void myLetterComb(string digits,vector<string> &res,string nums[],int idx,string s){
        if(idx == digits.size()){
            res.push_back(s);
            return;
        }
        
        string myVal = nums[digits[idx] - '0'];
        for(int i = 0 ; i < myVal.size();i++){
            myLetterComb(digits,res,nums,idx+1,s+myVal[i]);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> res;
        string nums[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        myLetterComb(digits,res,nums,0,"");
        
        return res;
        
        
    }
};