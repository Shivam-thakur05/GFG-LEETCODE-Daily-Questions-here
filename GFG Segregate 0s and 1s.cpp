//first method to seperate zero with one's using sorting in the complexity of O(nlogn)
// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        sort(arr.begin(),arr.end());
    }
};


//Second method is to move non zero number with zero's and then reverse for correct manner.
//time Complexity :- O(n)
//Space Complexity :- O(1)
//better Approach

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int NonZeroNumberIdx = 0;
        for(int i =0; i < arr.size(); i++){
            if(arr[i] != 0){
                swap(arr[i],arr[NonZeroNumberIdx]);
                NonZeroNumberIdx++;
            }
        }
        int start = 0;
        int end = arr.size()-1;
        while(start <= end){
            swap(arr[start++],arr[end--]);
        }
    }
};
