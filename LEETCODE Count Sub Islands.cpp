class Solution {
private:
    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i, int j){
        //if out of bound
        if(i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size()){
            return true;
        }
        if(grid2[i][j] != 1) return true;

        grid2[i][j] = -1; //mark visited

        bool result = (grid1[i][j] == 1);      //grid1[i][j] must have 1

        result = result & checkSubIsland(grid1, grid2, i+1, j); //up
        result = result & checkSubIsland(grid1, grid2, i-1, j); //down
        result = result & checkSubIsland(grid1, grid2, i, j+1); //right
        result = result & checkSubIsland(grid1, grid2, i, j-1);   //left

        return result;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //DFS
        int subIslands = 0;
        int m = grid2.size();
        int n = grid2[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] == 1 && checkSubIsland(grid1,grid2, i, j)){
                    subIslands++;
                }
            }
        }
        return subIslands;
    }
};
