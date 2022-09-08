class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1;
        int right = 1000000000;
        int ans = right;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(canEatInTime(piles, mid, h)){
                ans = min(mid,ans);
                right = mid - 1;
            }else left = mid + 1;
        }
        return ans;
    }
    bool canEatInTime(vector<int>& piles, int k, int h){
        long long hours = 0;
        for(long long pile : piles){
            hours += ceil(pile*1.0/k);
        }
        return hours <= h;
    
    }
};