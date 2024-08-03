//brute force solution
//Time Complexity = O(n)^2, Space Complexity = O(1)


class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int idx = -1;  // Initialize idx to -1 to indicate no celebrity found
        
        for (int i = 0; i < row; i++) {
            bool isCelebrity = true;
            for (int j = 0; j < col; j++) {  // Fix the loop variable here, should be 'j' instead of 'i'
                if (mat[i][j] == 1) {
                    isCelebrity = false;
                    break;
                }
            }
            if (isCelebrity) {
                idx = i;
                for (int k = 0; k < row; k++) {
                    if (k != idx && mat[k][idx] == 0) {  // Fix the condition, we should check if mat[k][idx] == 0
                        return -1;  // If anyone doesn't know idx, idx is not a celebrity
                    }
                }
                return idx;  // If the candidate passes the check, return the index
            }
        }
        return -1;  // If no celebrity is found, return -1
    }
};


//Optimal Solution O(n) :- Using Stack 
// Time Complexity :- O(n), Space Complexity :- O(1)

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int candidate = 0;
        
        // Find the candidate
        for (int i = 1; i < n; ++i) {
            if (mat[candidate][i] == 1) {
                candidate = i;
            }
        }
        
        // Verify the candidate
        for (int i = 0; i < n; ++i) {
            if (i != candidate && (mat[candidate][i] == 1 || mat[i][candidate] == 0)) {
                return -1;
            }
        }
        
        return candidate;
    }
};
