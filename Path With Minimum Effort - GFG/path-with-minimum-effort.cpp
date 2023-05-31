//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
       priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        
        dist[0][0] = 0;
        
        
        pq.push({0,{0,0}});
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        
        while(!pq.empty()){
            auto i = pq.top();
            int dis = i.first;
            int r = i.second.first;
            int c = i.second.second;
            pq.pop();
            
            if(r == n-1 && c == m-1) return dis;
            
            
            for(int i =0;i < 4;i++){
                int newr = delrow[i] + r;
                int newc = delcol[i] + c;
                
                
                if(newr < n && newr >= 0 && newc <m && newc >= 0){
                    int newEffort = max(abs(heights[r][c] - heights[newr][newc]),dis);
                    
                    if(newEffort < dist[newr][newc]){
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort,{newr,newc}});
                    }
                }
                
            }
            
            
            
        }
        return 0;
        
        
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends