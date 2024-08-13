class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long maxSum = 0;
        long currSum = 0;
        long temp = 0;

        for(long i = 0; i < K; i++){
            currSum += Arr[i];
        }
        
        for(long i = K; i < Arr.size(); i++){
            maxSum = max(currSum,maxSum);
            currSum = currSum - Arr[i-K];
            currSum += Arr[i];
        }
        
    maxSum = max(currSum,maxSum);
    return maxSum;   
    }
};
