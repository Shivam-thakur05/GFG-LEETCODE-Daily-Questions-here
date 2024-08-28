
class Solution {
  public:
    static bool solve(pair<int,int> &a, pair<int,int> &b){
        if(a.second > b.second) return true;
        else if(a.second < b.second) return false;
        else{
            return a.first < b.first;
        }
    }
    
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int,int> mp;
        vector<int>ans;
        vector<pair<int,int>>temp;
        
        //store the freq in the map
        for(auto it : arr) mp[it]++;
        
        //store the freq and the element as well
        for(auto it : arr){
            temp.push_back({it,mp[it]});
        }
        //sort the array based on freq
        sort(temp.begin(), temp.end(), solve);
        
        //only wae have to return array
        for(auto it : temp) ans.push_back(it.first);
        
        return ans;
    }
};
