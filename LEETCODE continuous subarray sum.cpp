#include <vector>
#include <unordered_map>

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;  // There must be at least two elements in the subarray

        // Map to store the remainder and its corresponding index
        unordered_map<int, int> remainderMap;
        remainderMap[0] = -1;  // Handle the case where the subarray starts from index 0

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int remainder = sum % k;

            if (remainderMap.find(remainder) != remainderMap.end()) {
                // Check if the subarray length is at least 2
                if ((i - remainderMap[remainder]) > 1) return true;
            } else {
                // Store the first occurrence of this remainder
                remainderMap[remainder] = i;
            }
        }

        return false;
    }
};
