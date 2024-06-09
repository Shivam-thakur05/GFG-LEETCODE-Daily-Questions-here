class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        unordered_map<int, int> remainderMap;
        remainderMap[0] = 1;  // count of zero is one

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int remainder = sum % k;
            if(remainder < 0) remainder += k;       //edge cases for negative value
    
            if (remainderMap.find(remainder) != remainderMap.end()) {
                // Check if the subarray length is at least 2
                count += remainderMap[remainder];
            }
            remainderMap[remainder]++;      //increasing the count of that remainder 
        }

        return count;
    }
};
