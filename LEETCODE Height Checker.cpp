class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int>ans;
        for(int i = 0; i < n; i++){
            ans.push_back(heights[i]);
        }
        sort(ans.begin(),ans.end());
        int count = 0;
        for(int i = 0; i < n; i++){
            if(ans[i] != heights[i]) count++;
        }
        return count;
    }
};
