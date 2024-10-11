class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto it : arr){
            mp[it]++;
        }
        vector<int>ans(arr.size());
        for(int i = 0; i < arr.size(); i++){
            if(mp.find(i) != mp.end()){
                ans[i] = i;
            }
            else{
                ans[i] = -1;
            }
        }
        return ans;
    }
};
