class Solution {
public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int i = 0, j = 0, count = 0;
        
        // We need to find the k-th element in the merged array
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                count++;
                if (count == k) return arr1[i];
                i++;
            } else {
                count++;
                if (count == k) return arr2[j];
                j++;
            }
        }
        
        // If elements remain in arr1
        while (i < n) {
            count++;
            if (count == k) return arr1[i];
            i++;
        }
        
        // If elements remain in arr2
        while (j < m) {
            count++;
            if (count == k) return arr2[j];
            j++;
        }
        
        // If k is larger than the number of elements in both arrays
        return -1;
    }
};
