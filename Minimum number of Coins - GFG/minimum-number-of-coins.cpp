//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> ans = {2000,500,200,100,50,20,10,5,2,1};
        vector<int> final;
        
            for(int i =0;i < ans.size() && N > 0;i++){
                if(ans[i] <= N){
                    int x = N/ans[i];
                    N-= (ans[i]*x);
                    for(int j = 0;j < x;j++){
                        final.push_back(ans[i]);
                    }
                    
                }
            }
        
        return final;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends