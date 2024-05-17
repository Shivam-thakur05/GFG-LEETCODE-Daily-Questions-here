//first method to find the pair using map of T.C. =  O(n) and S.C. = O(n)

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(x==0) {
                if(mp[arr[i]]>1){
                    return 1;}
            }
            else{
                if(mp.find(arr[i]+x)!=mp.end()){
                    return 1; } 
            }
        }
        return -1; 
    }
};


//second method to find the pair using two pointer and binary search  T.C. = O(n logn) , S.C. = O(1).


class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++)
        {
            int low = i;
            int high = n-1;
            while(low <= high)
            {
                int mid = (low + high)/2;
                if((arr[mid] == arr[i] + x) && (mid != i))
                    return 1;
                else if(arr[mid] > arr[i] + x)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return -1;
    }
};
