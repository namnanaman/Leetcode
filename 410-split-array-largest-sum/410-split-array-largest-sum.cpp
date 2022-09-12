class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = INT_MIN;
        int high = 0;
        
        for(int  i : nums){
            low = max(i,low);
            high += i;
        }
        int ans = 0;
        while(low <= high){
            int mid = low +(high - low)/2;
            if(isPossible(nums,m,mid)){
                ans = mid;
                high = mid -1;
            }else{
                low = mid + 1;
            }
            
        }
        return ans;
    }
    
    bool isPossible(vector<int> &nums,int parts,int mid){
        int sum = 0;
        int cnt = 1;
        
        for(int  i : nums){
            sum += i;
            
            if(sum > mid){
                sum = i;
                cnt += 1;
            }
        }
        return cnt <= parts;
    }
};