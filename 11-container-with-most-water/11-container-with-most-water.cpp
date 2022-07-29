class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        
        int max_water = -1e9;
        
        while(left < right){
            if(height[left] < height[right]){
                max_water = max(max_water,height[left] * (right - left));
                left++;
            }else{
                max_water = max(max_water,height[right] * (right-left));
                right--;
            }
        }
        return max_water;
    }
};