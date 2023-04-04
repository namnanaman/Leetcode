class Solution {
public:
     
    void dfs(int row,int col,int delrow[],int delcol[],vector<vector<int>> &vis,vector<vector<char>> &grid){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0; i < 4;i++){
            
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
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
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