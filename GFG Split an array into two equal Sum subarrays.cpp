class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int total = 0;
        int remaining = 0;
        for(int i = 0; i < arr.size(); i++){
            total += arr[i];
        }
        for(int i = 0; i < arr.size(); i++){
            total -= arr[i];
            remaining += arr[i];
            if(total == remaining) return true;
        }
        return false;
    }
};
