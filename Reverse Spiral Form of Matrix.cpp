
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&matrix)  {
        vector<int>ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int totalDigit = row*col;
        
        int rowStart = 0,colStart = 0, rowLast = row - 1, colLast = col - 1;
        
        while(ans.size() < totalDigit){
            for(int i = colStart; i <= colLast && ans.size() < totalDigit; i++) ans.push_back(matrix[rowStart][i]);
            rowStart++;
            for(int i = rowStart; i <= rowLast && ans.size() < totalDigit; i++) ans.push_back(matrix[i][colLast]);
            colLast--;
            for(int i = colLast; i >= colStart && ans.size() < totalDigit; i--) ans.push_back(matrix[rowLast][i]);
            rowLast--;
            for(int i = rowLast; i >= rowStart && ans.size() < totalDigit; i--) ans.push_back(matrix[i][colStart]);
            colStart++;
        }
        int start = 0;
        int end = ans.size()-1;
        while(start <= end){
            swap(ans[start++],ans[end--]);
        }
        return ans;
    }
};
