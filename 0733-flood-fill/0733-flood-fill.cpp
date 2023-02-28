class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n  = image.size();
        int m  = image[0].size();
        if(image[sr][sc] == color) return image;
        
        queue<vector<int>> q;
        int base = image[sr][sc];
        image[sr][sc] = color;
        q.push({sr,sc});
        
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,0,-1};
        
        while(!q.empty()){
            int r = q.front()[0];
            int c = q.front()[1];
            image[r][c] = color;
            q.pop();
            for(int i = 0;i < 4;i++){
                int nr = r + dr[i];
                int nc  = c + dc[i];
                if(nr >= 0 && nr < n && nc >=0 && nc < m && image[nr][nc] == base ){
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
            
            
        }
        return image;
        
        
    }
};