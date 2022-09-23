class Solution {
public:
    
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>&freq,string &word,int idx,int i,int j){
        if(idx == word.size() - 1) return true;
        freq[i][j] = true;
        
        if(i > 0 && !freq[i-1][j] && word[idx+1] == board[i-1][j] && dfs(board,freq,word,idx+1,i-1,j)) return true;
        
        if(i < board.size() - 1 && !freq[i+1][j] && word[idx+1] == board[i+1][j] && dfs(board,freq,word,idx+1,i+1,j)) return true;
        
        if(j < board[0].size() - 1 && !freq[i][j+1] && word[idx+1] == board[i][j+1] && dfs(board,freq,word,idx+1,i,j+1)) return  true;
        
        if(j > 0 && !freq[i][j-1] && word[idx+1] == board[i][j-1] && dfs(board,freq,word,idx+1,i,j-1)) return true;
        
        
        freq[i][j] = false;
        return false;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        
        vector<vector<bool>> freq(r,vector<bool>(c,false));
        
        
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                if(board[i][j] == word[0] && dfs(board,freq,word,0,i,j))
                    return true;
            }
        }
        return false;
        
    }
};