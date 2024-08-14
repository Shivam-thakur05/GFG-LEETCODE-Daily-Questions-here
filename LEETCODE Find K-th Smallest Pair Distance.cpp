// Brute Force Cpp: (TLE)- 
// 1. Using vector:- 
int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> temp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                temp.push_back(abs(nums[i] - nums[j]));
            }
        }
        sort(temp.begin(), temp.end());
        return temp[k-1];
    }

// 2. Using maxHeap:- TLE occur

 priority_queue<int> maxHeap;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int absDiff = abs(nums[i] - nums[j]);
                maxHeap.push(absDiff);
                if(maxHeap.size() > k) {
            maxHeap.pop();
        }
            }
        }
        
        return maxHeap.top();
    }

// using Vector 
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElement = *max_element(nums.begin(),nums.end());
        vector<int> ans(maxElement+1,0);

        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                int diff = abs(nums[i] - nums[j]);
                ans[diff]++;
            }
        }
        for(int i = 0; i < maxElement+1; i++){
            k -= ans[i];
            if(k <= 0){
                return i;
            }
        }
        return -1;
        
    }
};
