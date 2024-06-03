class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
    int countOne = 0;
    int countTwo = 1;
    int ans = 1;
    int mod = 1e9+7;
        for(int i = 2; i < n; i++){
            int sum = (countOne+countTwo)%mod;
            ans = (((ans%mod)*2)%mod+sum)%mod;
            countOne = countTwo;
            countTwo = sum;
        }
        return ans;
    }
};
