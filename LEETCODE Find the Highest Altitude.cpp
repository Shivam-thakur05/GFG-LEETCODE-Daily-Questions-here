class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int temp = 0;

        for(int i = 0; i < gain.size(); i++){
            temp += gain[i];
            maxAltitude = max(maxAltitude,temp);
        }
        
        return maxAltitude;
    }
};
