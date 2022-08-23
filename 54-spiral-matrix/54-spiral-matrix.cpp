class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         if (matrix.empty())
        return {};
    vector<int> res;
    int left, right, top, down, index;
    left = top = 0, down = matrix.size()-1, right = matrix[0].size()-1;
    while (left <= right && top <= down) {
        for ( int j = left; j <= right; j++)
            res.push_back(matrix[top][j]);
        top++;
        for ( int i = top; i <= down; i++)
            res.push_back(matrix[i][right]);
        right--;
        if (top <= down) {
            for(int j = right; j >= left; j--)
                res.push_back(matrix[down][j]);
            down--;
        }
        if (left <= right) {
            for (int i = down; i >= top; i--)
                res.push_back(matrix[i][left]);
            left++;
        }
    }
    return res;
    }
};