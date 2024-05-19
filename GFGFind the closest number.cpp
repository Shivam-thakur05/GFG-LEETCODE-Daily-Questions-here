class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int start = 0;
        int end = n-1;
        int closestIndex = -1;
        int closestDifference = INT_MAX;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int difference = abs(arr[mid] - k);
            
            if (difference <= closestDifference) {
                if(closestDifference == difference) closestIndex = max(closestIndex,mid);
                else closestIndex = mid;
                closestDifference = difference;
            }
            
            if (arr[mid] < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return arr[closestIndex];
    } 
};
