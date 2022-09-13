class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size();
        int y = nums2.size();
        
        if(x  >  y){
            return findMedianSortedArrays(nums2,nums1);
        }
       int low = 0;
        int high = x;
        
        while(low <= high){
            int partitionX = (low + high)/2;
            int partitionY = (x + y + 1)/2 - partitionX;
            
            int leftX = partitionX == 0 ? -1e9 : nums1[partitionX-1];
            int rightX = partitionX == x ? 1e9 : nums1[partitionX];
            
            int leftY = partitionY == 0 ? -1e9 : nums2[partitionY-1];
            int rightY = partitionY == y ? 1e9 : nums2[partitionY];
            
            if(leftX <= rightY && leftY <= rightX){
                if((x+y)%2 == 0){
                    return (double)(max(leftX,leftY) + min(rightX,rightY))/2;
                }else
                    return max(leftY,leftX);
            }else if(leftX > rightY){
                high = partitionX - 1;
            }else{
                low  = partitionX + 1;
            }
            
        }
        return 0.0;
    }
};