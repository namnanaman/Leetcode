class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        if(n < m*k) return -1;
        
        int low = INT_MAX;
        int high = INT_MIN;
        
        for(int i : bloomDay){
            low = min(i,low);
            high = max(i,high);
            
        }
        
        int curr,adj,mid;
        int ans = 0;
        
        while(low <= high){
            mid = low + (high - low)/2;
            
            adj = 0;
            curr = 0;
            
            for(int i = 0;i < n;i++)
            {
                if(bloomDay[i] > mid) adj = 0;
                else{
                    adj++;
                    if(adj == k){
                        curr+= 1;
                        adj= 0;
                    }
                    if(curr >= m) break;
                }
                
            }
            if(curr < m) low = mid + 1;
            else {
                ans =  mid;
                high = mid - 1;
            
            }
            
        }
        
        return ans;
    }
};