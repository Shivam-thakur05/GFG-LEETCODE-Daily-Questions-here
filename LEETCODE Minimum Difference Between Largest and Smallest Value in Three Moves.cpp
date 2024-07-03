class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return 0;

        sort(nums.begin(), nums.end());

        // Considering the four possible ways of changing up to three elements
        int min_diff = INT_MAX;
        // Changing 0 elements from the start and 3 from the end
        min_diff = min(min_diff, nums[n-4] - nums[0]);
        // Changing 1 element from the start and 2 from the end
        min_diff = min(min_diff, nums[n-3] - nums[1]);
        // Changing 2 elements from the start and 1 from the end
        min_diff = min(min_diff, nums[n-2] - nums[2]);
        // Changing 3 elements from the start and 0 from the end
        min_diff = min(min_diff, nums[n-1] - nums[3]);

        return min_diff;
    }
};
