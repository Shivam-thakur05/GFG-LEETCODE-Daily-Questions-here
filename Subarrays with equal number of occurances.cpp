//brute force solution TLE
class Solution {
public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        int n = arr.size();
        int isSame = 0;

        for (int i = 0; i < n; ++i) {
            int xCount = 0, yCount = 0;
            for (int j = i; j < n; ++j) {
                if (arr[j] == x) xCount++;
                if (arr[j] == y) yCount++;
                if (xCount == yCount) isSame++;
            }
        }

        return isSame;
    }
};


//optimal solution

int count=0;
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=1;
        for(auto i:arr)
        {
            if(i==x)
            {
                sum++;
            }
            else if(i==y)
            {
                sum--;
            }
            
            count+= mp[sum];
            mp[sum]++;
        }
        
        return count;
