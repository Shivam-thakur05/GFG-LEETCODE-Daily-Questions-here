class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > arr) {
        int maxRow = 0;
        int ans = -1;
        for(int i = 0;i < arr.size(); i++){
            int temp = 0;
            for(int j = 0; j < arr[0].size(); j++){
                if(arr[i][j] == 1) temp++;
            }
            if(maxRow < temp){
                maxRow = temp;
                ans = i;
            }
        }
        return ans;
    }
};
