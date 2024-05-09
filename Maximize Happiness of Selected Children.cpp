class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        //sort the happiness in descending order
        sort(happiness.rbegin(),happiness.rend());
        int count = 0;
        for(int i = 0; i < k; i++){
            ans += max(happiness[i]-count,0);
            count++;
        }
        return ans;
    }
};
