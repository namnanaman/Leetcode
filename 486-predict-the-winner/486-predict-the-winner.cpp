class Solution {
public:
//     bool fun1(vector<int>& nums,int i,int j,int p1,int p2,bool p1turn)
//     {
//         if(i>j)
//             return p1>=p2;
        
//        if(p1turn)
//        {
//            return fun1(nums,i+1,j,p1+nums[i],p2,!p1turn)||fun1(nums,i,j-1,p1+nums[j],p2,!p1turn);
//        }
//        else
//        {
//             return fun1(nums,i+1,j,p1,p2+nums[i],!p1turn)&&fun1(nums,i,j-1,p1,p2+nums[j],!p1turn);
//        }
        
//     }
    
    bool f(vector<int>& nums,int i,int j,int score1,int score2,bool p1turn){
        if(i>j){
            return score1>=score2;
        }        
        if(p1turn){
            
            return f(nums,i+1,j,score1+nums[i],score2,!p1turn)||f(nums,i,j-1,score1+nums[j],score2,!p1turn);
        }else{
            return f(nums,i+1,j,score1,score2+nums[i],!p1turn)&&f(nums,i,j-1,score1,score2+nums[j],!p1turn);
        }
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return f(nums,0,n-1,0,0,true);
    }
};