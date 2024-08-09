class Solution {
  public:
    int Maximize(vector<int> arr) {
        int result = 0;
        int MOD = 1000000007;
        sort(arr.begin(),arr.end());
        for(int i = 0; i < arr.size(); i++){
            result = (result + (arr[i]*i)%MOD )%MOD;
        }
        return result;
    }
};
