class Solution {
public:
    string nearestPalindromic(string s) {
        int n = s.length();
        
        // Handle single digit cases
        if (n == 1) {
            return to_string((s[0] - '0') - 1);
        }

        // Generate possible palindromes
        vector<string> candidates;

        // Case 1: Lower bound (like "1000" -> "999")
        candidates.push_back(string(n - 1, '9'));

        // Case 2: Higher bound (like "999" -> "1001")
        string higher = "1" + string(n - 1, '0') + "1";
        candidates.push_back(higher);

        // Case 3: Mirror the first half and generate palindromes
        string prefix = s.substr(0, (n + 1) / 2);
        long long prefixNum = stoll(prefix);
        for (long long i : {prefixNum - 1, prefixNum, prefixNum + 1}) {
            string candidate = to_string(i);
            string mirror = candidate + string(candidate.rbegin() + (n % 2), candidate.rend());
            candidates.push_back(mirror);
        }

        // Remove the original number if it's a palindrome
        string originalPalindrome = s;
        sort(candidates.begin(), candidates.end());

        // Determine the closest palindrome
        string ans = "";
        long long minDiff = LLONG_MAX, originalNum = stoll(s);
        for (string candidate : candidates) {
            if (candidate != s) {
                long long candidateNum = stoll(candidate);
                long long diff = abs(candidateNum - originalNum);
                if (diff < minDiff || (diff == minDiff && candidateNum < stoll(ans))) {
                    ans = candidate;
                    minDiff = diff;
                }
            }
        }

        return ans;
    }
};
