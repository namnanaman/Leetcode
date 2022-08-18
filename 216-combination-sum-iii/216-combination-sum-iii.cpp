class Solution {
public:
    vector<vector<int>> ans;
    int Sum(vector<int> &combination){
        int vectorSum = 0;
        
        for(auto i : combination){
            vectorSum += i;
        }
        return vectorSum;
    }
    void f(int k,int n,vector<int> &combination,int num){
        if(k == 0){
            if(Sum(combination) == n){
                ans.push_back(combination);
            }
            return;
        }
        
        if(num > 9) return;
        combination.push_back(num);
        f(k-1,n,combination,num+1);
        
        combination.pop_back();
        f(k,n,combination,num+1);
        
        
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
    
        
        vector<int> combination;
        
        f(k,n,combination,1);
        return ans;
    }
};