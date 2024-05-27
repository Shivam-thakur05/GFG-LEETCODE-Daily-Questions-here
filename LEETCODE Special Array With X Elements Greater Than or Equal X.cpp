class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            freq[min(n,num)]++;

        }
        int cum_sum = 0;
        for(int x =n; x >= 0; x--){
            cum_sum += freq[x];
            if(x == cum_sum){
                return x;
            }
        }
        return -1;
    }
};
