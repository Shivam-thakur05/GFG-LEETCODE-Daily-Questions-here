//first method using recursion
class Solution {
public:
    int solve(vector<int>&nums, int i, int Xor) {
        //base case
        if(i == nums.size()) return Xor;

        int include = solve(nums, i+1, nums[i]^Xor);
        int exclude = solve(nums, i+1, Xor);

        return include+exclude;

    }

    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
    }
};


//second method applied bit manipulation [optimal Approach]

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int i : nums){
            result |= i;
        }
       return result << (n-1);
    }
};
