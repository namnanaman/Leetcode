class Solution {
public:
//     void generateCombinations(int n, int k, int idx, vector<int>& chosen,vector<vector<int>>& combs) {
//         if (chosen.size() == k) {
//             combs.push_back(chosen);
//             return;
//         }
//         for(int i = idx; i <= n; i++) {
//             chosen.push_back(i);
//             generateCombinations(n, k, i + 1, chosen, combs);
//             chosen.pop_back();
//         }
//     }

    void f(int n,int k,int idx,vector<vector<int>> &ans,vector<int> &small){
        if(small.size() == k){
            ans.push_back(small);
            return;
        }
        
        for(int i = idx;i <= n;i++){
            small.push_back(i);
            f(n,k,i+1,ans,small);
            small.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        
        vector<int> small;
        
        f(n,k,1,ans,small);
        
        return ans;
    }
    
//     void generateCombinations(int n, int k, int idx, vector<int>& chosen,vector<vector<int>>& combs) {
//         if (chosen.size() == k) {
//             combs.push_back(chosen);
//             return;
//         }
//         for(int i = idx; i <= n; i++) {
//             chosen.push_back(i);
//             generateCombinations(n, k, i + 1, chosen, combs);
//             chosen.pop_back();
//         }
//     }

//     vector<vector<int>> combine(int n, int k) {
//         vector<int> chosen;
//         vector<vector<int>> combs;
//         generateCombinations(n, k, 1, chosen, combs);
//         return combs;        
//     }
};