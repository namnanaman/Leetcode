//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  
    void dfs(int node,stack<int> &st,int vis[],vector<pair<int,int>> adj[]){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            int v = it.first;
            if(!vis[v]){
                dfs(v,st,vis,adj);
            }
        }
        
        
        st.push(node);
    }
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
            vector<pair<int,int>>  adj[N];
            
            for(int i = 0;i < M;i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int val = edges[i][2];
                
                adj[u].push_back({v,val});
                
            }
            int vis[N] = {0};
            stack<int> st;
            for(int i = 0 ; i < N;i++){
                if(!vis[i]){
                    dfs(i,st,vis,adj);
                }
            }
            
            vector<int> ans(N); 
            for(int i  =0 ;i < N;i++){
                ans[i]  = 1e9;
            }
            
            ans[0] = 0;
            vector<int> f;
            
            while(!st.empty()){
                
                int node = st.top();
                st.pop();
                
                for(auto x : adj[node]){
                    int v = x.first;
                    int wt = x.second;
                    if(wt + ans[node] < ans[v]){
                        ans[v] = wt + ans[node];
                    }
                }
                
                
            }
                for (int i = 0; i < N; i++) {
                    if (ans[i] == 1e9) ans[i] = -1;
                 }
        
           
            return ans;
            
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends