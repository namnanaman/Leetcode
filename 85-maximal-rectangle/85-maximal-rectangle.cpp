class Solution {
public:
    int MAH(vector<int> heights){
        int n = heights.size();
        int to_right[n];
        
        stack<int> st;
        
        for(int i = n-1;i >= 0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            to_right[i] = st.empty() ? n : st.top();
            
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        int area = INT_MIN;
        for(int i =0 ;i <n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            int to_left = st.empty() ? -1 : st.top();
            
            area = max(area,(to_right[i] - to_left-1)* heights[i]);
            st.push(i);
            
        }
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int c = matrix[0].size(); 
        int r = matrix.size();
        vector<int> v;
        for(int j = 0;j < c;j++){
            v.push_back(matrix[0][j] - '0');
        }
        int mh = MAH(v);
        
        for(int i = 1;i < r;i++){
            for(int j = 0;j < c;j++){
                if(matrix[i][j] == '0'){
                    v[j] = 0;
                }else{
                    v[j]  = v[j] + (matrix[i][j]-'0');
                }
            }
            mh = max(mh,MAH(v));
        }
        
        return mh;
    }
    
}; 