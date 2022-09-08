class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) { 
        int low = 1;
        int high = 1000000000;
        
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;

            
            if(checkIfItCanEat(piles,h,mid)){
                ans =min(mid,ans);
                high = mid - 1;
            }else 
                low = mid + 1;
            
        }
        return ans;
        
        
    }
    
    bool checkIfItCanEat(vector<int> &piles,int h,int mid){
        long long hrs = 0;
        
        for(int  i : piles){
            hrs += ceil(i*1.0/mid);
        }
        
        return hrs <= h;
    }
};