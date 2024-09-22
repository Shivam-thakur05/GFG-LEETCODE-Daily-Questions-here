// Brute force approach (TLE, MLE)

class Solution {
private:
    void solve(long long curr, long long limit, int &k, long long &temp) {
        if (curr > limit || k == 0) return;
        temp = curr;
        k--;  // Decrement k when a valid number is found
        if (k == 0) return;  // If k reaches 0, stop further processing
        for (int append = 0; append <= 9; append++) {
            long long num = curr * 10 + append;
            if (num > limit) return;
            solve(num, limit, k, temp);
            if (k == 0) return;  // If k reaches 0, stop further processing
        }
    }

    long long lexicalOrder(long long n, int &k) {
        long long ans = -1;
        for (int startNum = 1; startNum <= 9; startNum++) {
            solve(startNum, n, k, ans);
            if (k == 0) break;  // Stop if k-th number is found
        }
        return ans;
    }

public:
    int findKthNumber(int n, int k) {
        long long res = lexicalOrder(n, k);
        return static_cast<int>(res);
    }
};



//second Approach

class Solution {
private:
    int Count(long curr, long next, int n){
        int countNum = 0;

        while(curr <= n){
            countNum += (next-curr);

            curr *= 10;
            next *= 10;

            next = min(next, long(n+1));
        }
        return countNum;
    }
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1; //since we start from the first number (1), we need k-1 more numbers

        while(k > 0){
            int count = Count(curr, curr+1, n);
            if(count <= k){
                curr++;
                k -= count; //skipping the elements under curr prefix tree
            } else{
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};
