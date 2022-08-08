class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1;i <= n;i++){
            q.push(i);
        }
        
        while(q.size() > 1){
            int r = k;
            
            while(r > 1){
                int front  = q.front();
                q.pop();
                q.push(front);
                r--;
            }
            q.pop();
        }
        return q.front();
    }
};