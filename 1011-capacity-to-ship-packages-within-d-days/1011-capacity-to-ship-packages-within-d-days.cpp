class Solution {
public:
    int shipWithinDays(vector<int>& wt, int days) {
        int low =wt[0];
        int high = 0;
        
        for(int i : wt){
            low = max(low,i);
            high += i;
        }
        
        int ans = 0;
        
        while(low <= high){
            int mid = low +(high - low )/2;
            
            if(isPossible(wt,mid,days)){
                ans = mid;
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    bool isPossible(vector<int>& wt,int mid,int days){
        int cnt = 1;
        int weight = 0;
        for(int i : wt){
            weight += i;
            
            if(weight > mid){
                weight = i;
                cnt++;
            }
        }
        return cnt <= days;
    }
};