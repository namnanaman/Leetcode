//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
         int MOD = 1e9 +7;
        vector<vector<long long>> adjList[n+1];
        
        for(int i = 0 ; i < roads.size() ; i++){
            long long u = roads[i][0];
            long long v = roads[i][1];
            long long time = roads[i][2];
            
            adjList[u].push_back({v, time});
            adjList[v].push_back({u, time});
        }
        
        
        // direct dijkstra lagao and lage haath "ways" found out kro
        
        vector<long long> ways(n,0);
        ways[0] = 1;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        pq.push({0, 0}); // dist, node
        
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            
            long long d = front[0];
            long long currcity = front[1];
            
            for(auto &next : adjList[currcity]){
                long long nextcity = next[0];
                long long edgeWt = next[1];
                if( d + edgeWt < dist[nextcity]){
                    dist[nextcity] = d + edgeWt;
                    pq.push({ d + edgeWt , nextcity});
                    ways[nextcity] = ways[currcity]%MOD;
                }
                else if(d + edgeWt == dist[nextcity]){
                    ways[nextcity] += (ways[currcity])%MOD;   
                }
            }
        }
        
        return ways[n-1]%MOD;
        
        // vector<pair<int,int>> adj[n];
        
        // for(auto it : roads){
        //     adj[it[0]].push_back({it[1],it[2]});
        //     adj[it[1]].push_back({it[0],it[2]});
        // }
        
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        // vector<int> dist(n,1e9);
        // vector<int> ways(n,0);
        
        // dist[0] = 0;
        // ways[0] = 1;
        // pq.push({0,0});
        // int mod =(int)(1e9 + 7);
            
        // while(!pq.empty()){
        
        //     int node = pq.top().second;
        //     int dis = pq.top().first;
            
        //     pq.pop();
            
        //     for(auto  i : adj[node]){
        //         int adjnode = i.first;
        //         int edw = i.second;
                
                
        //         if(dis +edw < dist[adjnode] ){
        //             dist[adjnode] = dis + edw;
        //             pq.push({dis + edw,adjnode});
        //             ways[adjnode] = ways[node];
        //         }else if(dis + edw == dist[adjnode]){
        //             ways[adjnode] =(ways[node] + ways[adjnode]) % mod;
        //         }
                
                
        //     }
        // }
        // return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends