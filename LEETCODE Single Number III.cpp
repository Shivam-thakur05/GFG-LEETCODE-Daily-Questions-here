//Approach 1 :- using map   T.C - O(n) , S.C. - O(n)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]] == 1)
            ans.push_back(nums[i]);
        }
        return ans;
    }
};


//Approach 2 :- using sorting   T.C - O(nlogn) , S.C - O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                i++;
            }
            else if(nums[i] != nums[i+1]){
                ans.push_back(nums[i]);
            }
        }
        if(nums[nums.size()-1] != nums[nums.size()-2]){
            ans.push_back(nums[nums.size()-1]);
        }
        return ans;
    }
};


//Approach 3 :- using bit manipulation   T.C - O(n) , S.C - O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_r = 0;
        for(int num:nums){      //take xor of all nums elements
            xor_r ^= num;
        }
        //mask -> right most set bit search 
        int mask = (xor_r)&(-xor_r);
        int groupA = 0;
        int groupB = 0;
        for(int num:nums){
            if(num & mask){
                groupA ^= num;
            }
            else{
                groupB ^= num;
            }
        }
        return {groupA,groupB};
    }
};
