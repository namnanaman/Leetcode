class Solution {
public:
    bool isValid(int row,int col,vector<string> board){
         int duprow = row;
        int dupcol = col;
        while(row >= 0 && col >=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(row < board.size() && col >=0 ){
            if(board[row][col] == 'Q') return false;
            col--;
            row++;
            
        }
        row=duprow;
        col=dupcol;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        return true;
    }
    void Solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0;row < n;row++){
            if(isValid(row,col,board)){
                board[row][col] = 'Q';
                Solve(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        
        vector<vector<string>> ans;
        
        string s(n,'.');
        
        vector<string> board(n);
        
        for(int i = 0;i < n;i++){
            board[i] = s;
        }
        
        
        Solve(0,board,ans,n);
        
        
        return ans;
        
        
        
    }
};