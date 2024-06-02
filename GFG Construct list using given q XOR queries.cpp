class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        vector<int>ans;
        int xor_value = 0;
        for(int i = 0; i < q; i++){
            int x = queries[i][1];
            if(queries[i][0] == 0){
                x^=xor_value;
                ans.push_back((x));
            }
            else if(queries[i][0] == 1){
                xor_value ^= x;
            }
        }
        ans.push_back(xor_value);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
