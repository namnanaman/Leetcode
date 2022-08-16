class Solution {
public:
    int Solve(int i,int j,vector<vector<int>> &grid){
        if(i <0 || j<0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= 0) return 0;
        grid[i][j] = -grid[i][j];
        
        int down =  Solve(i+1,j,grid);
        int right = Solve(i,j+1,grid);
        int up = Solve(i-1,j,grid);
        int left =  Solve(i,j-1,grid);
        
        auto res = max(left,max(right,max(up,down)));
        
        grid[i][j] = -grid[i][j];
        
        return res + grid[i][j];
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int maxi = 0;
        
        for(int i = 0; i < grid.size();i++){
            for(int j =0;j< grid[0].size();j++){
                
                maxi = max(maxi,Solve(i,j,grid));
            }
        }
        
        
        return maxi;
    }
};