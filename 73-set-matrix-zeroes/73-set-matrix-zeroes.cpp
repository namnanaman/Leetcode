class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int H = matrix.size();
        int W = matrix[0].size();
        vector<bool> row_zero(H);
        
        vector<bool> col_zero(W);

        for(int i =0;i < H;i++){
            for(int j =0;j < W;j++){
                if(matrix[i][j] == 0){ //1,1
                    row_zero[i] = true;
                    col_zero[j] = true;
                }
            }
        }
        for(int i =0;i < H;i++){
            for(int j = 0;j < W;j++){
                if(row_zero[i] || col_zero[j]){
                    matrix[i][j] = 0;
                }
            }
        }
        
        
    }
};