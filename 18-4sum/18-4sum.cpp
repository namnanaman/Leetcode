class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //  vector<vector<int>> total;
        // int n = nums.size();
        // if(n<4)  return total;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n-3;i++)
        // {
        //     if(i>0&&nums[i]==nums[i-1]) continue;
        //     if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
        //     if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
        //     for(int j=i+1;j<n-2;j++)
        //     {
        //         if(j>i+1&&nums[j]==nums[j-1]) continue;
        //         if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
        //         if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
        //         int left=j+1,right=n-1;
        //         while(left<right){
        //             int sum=nums[left]+nums[right]+nums[i]+nums[j];
        //             if(sum<target) left++;
        //             else if(sum>target) right--;
        //             else{
        //                 total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
        //                 do{left++;}while(nums[left]==nums[left-1]&&left<right);
        //                 do{right--;}while(nums[right]==nums[right+1]&&left<right);
        //             }
        //         }
        //     }
        // }
        // return total;
//         vector<vector<int>> ans;
//          int n = nums.size();
//         if(nums.size() < 4) return ans;
//         if(n == 4 && nums[0]+nums[1]+nums[2]+nums[3] == target) {
            
//             ans.push_back({nums[0],nums[1],nums[2],nums[3]});
//             return ans;
//         }
//         sort(nums.begin(),nums.end());
       
//         for(int i = 0;i<n;i++){
//             for(int j = i+1;j<n;j++){
//                 int front = j + 1;
//                 int back = n - 1;
//                 int target_2 = target - nums[i] - nums[j];
                
                
//                 while(front < back){
//                     int two_sum = nums[front] + nums[back];
                    
//                     if(two_sum < target_2){
//                         front ++;
//                     }else if(two_sum > target_2){
//                         back--;
//                     }else{
//                         vector<int> x(4,0);
//                         x[0] = nums[i];
//                         x[1] = nums[j];
//                         x[2] = nums[front];
//                         x[3] = nums[back];
//                         ans.push_back(x);
                        
//                         while(front < back && nums[front] == x[2]) ++front;
//                         while(front < back && nums[back] == x[3]) --back;
//                     }
                    
                    
//                 }
//                 while(j+1 < n && nums[j+1] == nums[j]) ++j;
//             }
//             while(i+1 < n && nums[i+1] == nums[i]) ++i;
//         }
        
//         return ans;
        vector<vector<int>> ans;
        int n = nums.size();
        if(n < 4) return ans;
        if(nums.empty()) return ans;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                long long target2 = (long long)target -(long long)nums[i]- (long long)nums[j];
                int front = j+1;
                int back = n-1;
                
                while(front < back){
                    long long twosum = (long long)nums[front] + (long long)nums[back];
                    
                    if(twosum < target2){
                        front++;
                    }else if(twosum > target2){
                        back--;
                    }else{
                        int x = nums[front];
                        int y = nums[back];
                        ans.push_back({nums[i],nums[j],nums[front],nums[back]});
                        
                        while(front < back && nums[front] == x) front++;
                        while(front < back && nums[back] == y) back--;
                    }
                }
                while(j +1 <n && nums[j+1] == nums[j]) j++;
                
            }
            while(i+1 < n && nums[i+1] == nums[i]) i++;
        }
        
        
        
        return ans;
    }
};