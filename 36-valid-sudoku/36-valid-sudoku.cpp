class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        unordered_map<char,int> row[9];
        unordered_map<char,int> col[9];
        unordered_map<char,int> box[9];
        
        
        for(int i =0; i < rows;i++){
            for(int j = 0; j < cols;j++){
                char c = board[i][j];
                
                if(c != '.' && (row[i][c]++ > 0 || col[j][c]++ > 0 || box[i/3*3+j/3][c]++ > 0)){
                    return false;
                }
            }
        }
        return true;
        
    }
};