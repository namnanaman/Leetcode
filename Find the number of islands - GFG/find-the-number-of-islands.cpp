//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(int row,int col,int delrow[],int delcol[],vector<vector<int>> &vis,vector<vector<char>> &grid){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0; i < 8;i++){
            
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow,ncol,delrow,delcol,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrow[] = {-1,-1,0,+1,+1,+1,0,-1};
        int delcol[] = {0,+1,+1,+1,0,-1,-1,-1};
        int cnt = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!vis[i][j] && grid[i][j] == '1' ){
                    cnt++;
                    dfs(i,j,delrow,delcol,vis,grid);
                }
            }
        }
        
        
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends