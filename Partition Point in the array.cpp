class Solution {

  public:
    int FindElement(vector<int>& arr) {
        int res = arr[0];
        int great = arr[0];
        int maxe = -1;
        for(int i = 1; i<arr.size(); i++){
            maxe = max(maxe, arr[i-1]);
            if(great >= arr[i]){
                res = -1;
            }
            
            if(res == -1 && great < arr[i] && maxe < arr[i]){
                res = arr[i];
                great = arr[i];
            }
        }
        return res;
    }
};
