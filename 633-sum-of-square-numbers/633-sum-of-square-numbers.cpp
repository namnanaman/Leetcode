class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 0)return false;
        int j = sqrt(c) ;
        int i = 0;
        
        while(i <=j){
            long long  x = (long long )i *i + (long long )j*j;
            
            if(x == c) return true;
            else if(x > c) j--;
            else i++;
        }
        
        return false;
    }
};