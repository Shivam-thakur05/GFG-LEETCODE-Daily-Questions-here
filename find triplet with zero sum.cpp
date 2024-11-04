//brute force T.C. -> O(n)^3, S.C. -> O(n)^2 
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        vector<vector<int>>ans;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    if((arr[i] + arr[j] + arr[k]) == 0){
                        vector<int>temp;
                        temp.push_back(i);
                        temp.push_back(j);
                        temp.push_back(k);
                        ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
};

//optimal solution T.C. -> O(n)^2, S.C. -> O(n)^2

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        vector<vector<int>>ans;
        int n = arr.size();
        unordered_map<int,vector<int>>mp;
        
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(mp.find(0 - (arr[i] + arr[j])) != mp.end()){
                    for(int n:mp[0-(arr[i]+arr[j])]){
                        if(n>j){
                            ans.push_back({i,j,n});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
