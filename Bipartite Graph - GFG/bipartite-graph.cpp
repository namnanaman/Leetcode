//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(int node,int sign, vector<int> adj[],vector<int> &col){
        col[node] = sign;
        
        for(auto i : adj[node]){
            if(col[i] == -1 ){
                if(dfs(i,!sign,adj,col) == false) return false;
            }
            else if(col[i] == sign){
                return false;
            }
        }
        return true;
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	    
	   vector<int> col(V,-1);
	    
	    for(int i = 0;i < V;i++){
	        if(col[i] == -1){
	            if(dfs(i,0,adj,col) == false) return false;
	        }
	    }
	    return true;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends