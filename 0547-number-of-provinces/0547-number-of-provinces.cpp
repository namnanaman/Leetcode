class Solution {
public:
    
    
    void dfs(int node,vector<int> adj[],vector<int> &vis){
        vis[node] = 1;
        for(auto s : adj[node]){
            if(!vis[s]){
                dfs(s,adj,vis);
            }
        }
        
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        
        vector<int> adj[V];
        
        for(int i =0;i < V;i++){
            for(int j = 0;j < V;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<int> vis(V,0);
        
        int count = 0;
        
        for(int i = 0;i <V;i++){
            if(!vis[i]){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
        
    }
};