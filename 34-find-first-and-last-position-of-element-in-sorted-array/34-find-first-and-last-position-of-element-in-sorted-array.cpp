class Solution {
public:
    int BinarySearch(vector<int> &nums,int &target,int index){
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(target > nums[mid]){
                low = mid + 1;
            }else if(target < nums[mid]){
                 high = mid -1;
            }
            else{
                ans = mid;
                if(index == -1){
                     high = mid-1;
                }
                   
                else{
                     low = mid + 1;
                }
                   
            }
                
            
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = BinarySearch(nums,target,-1);
        int idx2 = BinarySearch(nums,target,1);
        
        return {idx1,idx2};
    }
};