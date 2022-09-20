class Solution {
public:
    int countGoodNumbers( long long n) {
        long long result = n%2 == 0 ? 1 : 5 ;
        long long x = 20;
        int MOD = 1000000007;
        for(long long  i = n/2;i > 0;i/=2){
            if(i%2!= 0) result = result *x %MOD;
            
            x = x*x %MOD;
        }
        return (int)result;
    }
};