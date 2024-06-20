class Solution {
public:
    bool isPossibleToPlace(int mid, vector<int>&position, int m){
        int start = position[0];        //put the first ball in 0th position
        int countBalls = 1;
        for(int i = 1; i < position.size(); i++){
            int curr = position[i];
            //if midValue is equal or greater than 
            if(curr - start >= mid){
                countBalls++;
                start = curr;
            }
            if(countBalls == m) break;
        }
        return countBalls == m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        //sort the index
        sort(position.begin(),position.end());

        int minForce = 1;       //atleast minforce sould be 1
        int maxForce = position[n-1] - position[0];

        int result = 0;
        while(minForce <= maxForce){
            int mid = (minForce + maxForce)/2;
            if(isPossibleToPlace(mid,position,m)){
                //possible answer store in the result variable
                result = mid;
                minForce = mid+1;
            }
            else{
                maxForce = mid-1;
            }
        }
        return result;
    }
};
