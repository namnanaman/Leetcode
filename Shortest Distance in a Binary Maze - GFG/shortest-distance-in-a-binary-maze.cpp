//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
        int n = grid.size();
        int m = grid[0].size();
        if(source.first == destination.first && source.second == destination.second) return 0;
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        
        queue<pair<int,pair<int,int>>> q;
    
        dist[source.first][source.second] = 0;
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        q.push({0,{source.first,source.second}});
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            int dis = node.first;
            int r = node.second.first;
            int c = node.second.second;
            
            for(int i = 0;i < 4;i++){
                int newr = delrow[i] + r;
                int newc = delcol[i] + c;
                
                if(newr <n && newr >= 0 && newc < m &&  newc >= 0 && grid[newr][newc] == 1 && (dis + 1) < dist[newr][newc]){
                    dist[newr][newc] = dis + 1;
                    
                    if(newr == destination.first && newc == destination.second){
                        return dist[newr][newc];
                    }
                    
                    q.push({1+dis,{newr,newc}});
                    
                    
                }
                
            }
            
            
            
        }
        
        return -1;
        
        
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends