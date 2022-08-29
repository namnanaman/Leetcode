class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int H = matrix.size();
        int W = matrix[0].size();
        int col = 1;
        
        for(int i =0;i < H;i++){
            if(matrix[i][0] == 0) col = 0;
            for(int j = 1;j < W;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int rows = H-1;rows >= 0;rows--){
            for(int cols = W-1;cols >=1 ;cols--){
                if(matrix[rows][0] == 0 || matrix[0][cols] == 0){
                    matrix[rows][cols] = 0;
                }
            }
            if(col ==0) matrix[rows][0] = 0;
        }
    }
};