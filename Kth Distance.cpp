/*
Algorithm
Find element.
Store the index.
Check the distance.
Return TRUE when less than k.
Update the index.
Return FALSE.
Code:
  */

// User function template for C++

class Solution {
  public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        unordered_map<int, int>index;
        for(int i = 0 ; i < arr.size() ; i++){
            if(index.find(arr[i]) != index.end())
                if(i - index[arr[i]] <= k)
                    return true;
            index[arr[i]] = i;
        }
        return false;
    }
};
