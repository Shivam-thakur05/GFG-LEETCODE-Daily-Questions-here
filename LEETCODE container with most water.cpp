class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int i = 0;
        int j = height.size()-1;

        while(i < j){
            int width = j-i;
            int areaWater = min(height[i],height[j])*width;
            maxWater = max(maxWater, areaWater);
            //if i is already greater value then for maximum area we have to find j greater value
            if(height[i] > height[j]){
                j--;
            }
            else i++;
        }
        return maxWater;
    }
};
