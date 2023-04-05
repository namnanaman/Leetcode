//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int row,int col,int delrow[],int delcol[],vector<vector<int>> &vis,vector<vector<int>> &grid,vector<pair<int,int>> &x,int baserow,int basecol){
        vis[row][col] = 1;
        int trow = baserow-row;
        int tcol = basecol-col;
        
        x.push_back({trow,tcol});
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0;i < 4;i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1 ){
                dfs(nrow,ncol,delrow,delcol,vis,grid,x,baserow,basecol);
            }
        }
        
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        set<vector<pair<int,int>>> s;
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i = 0;i < n;i++){
            for(int j =0;j < m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    
                    vector<pair<int,int>> x;
                    dfs(i,j,delrow,delcol,vis,grid,x,i,j);
                    s.insert(x);
                }
                
            }
        }
        
        return s.size();
        
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends