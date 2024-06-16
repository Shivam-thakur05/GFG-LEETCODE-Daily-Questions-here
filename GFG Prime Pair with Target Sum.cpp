class Solution {
public:
    vector<int> getPrimes(int n) {
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        
        // Sieve of Eratosthenes
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Find two primes that sum to n
        for (int i = 2; i < n; i++) {
            if (isPrime[i] && isPrime[n - i]) {
                return {i, n - i};
            }
        }
        
        // Return {-1, -1} if no such pair exists
        return {-1, -1};
    }
};
