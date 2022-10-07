class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        
        for(int i = 0;i < nums.size();i++){
            if(st.empty() || nums[i] > 0 ){
                st.push(nums[i]);
            }else{
                while(true){
                    int top = st.top();
                    
                    if(top < 0){
                        st.push(nums[i]);
                        break;
                    }else if(top == -nums[i]){
                        st.pop();
                        break;
                    }else if(top > -nums[i]){
                        break;
                    }else{
                        st.pop();
                        if(st.empty()){
                            st.push(nums[i]);
                            break;
                        }
                    }
                }             
            }
        }
        
        vector<int> ans(st.size());
        
        for(int i = st.size()-1;i >= 0;i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
        
    }
};  