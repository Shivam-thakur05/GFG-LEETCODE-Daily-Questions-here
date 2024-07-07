class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        //remaining empty bottles
        int prevExtBottles = 0;

        while(numBottles > 0){
            //add into the ans
            ans += numBottles;
            //if any prev remaining bottle add them into number of bottles
            numBottles += prevExtBottles;
            //check for remaining bottles
            prevExtBottles = numBottles % numExchange;
            cout<<numBottles<<" ";
            //exchange empty to full water bottle
            numBottles /= numExchange;
        }
        
        return ans;
    }
};
