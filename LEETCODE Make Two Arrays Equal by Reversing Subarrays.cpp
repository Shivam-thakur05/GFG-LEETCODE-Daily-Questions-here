//Using sorting Algorithm   T.C. :- O(n log n), S.C. :- O(1)

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        if(target.size() != arr.size()) return false;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != target[i]){
                return false;
            }
        }
        return true;
    }
};

//Using Hasmap T.C. :- O(n), S.C.:- O(n)

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int i = 0; i < target.size(); i++) {
            mp[target[i]]++;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (mp.find(arr[i]) != mp.end() && mp[arr[i]] > 0) {
                mp[arr[i]]--;
            } else {
                return false;
            }
        }
        //is any count still remains than return false
        for (auto &entry : mp) {
            if (entry.second != 0) {
                return false;
            }
        }
        return true;
    }
};
