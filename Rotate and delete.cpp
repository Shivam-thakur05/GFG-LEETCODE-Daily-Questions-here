
// T.C. - O(n2), S.C. - O(1)

class Solution {
  private:
    void rotateArray(vector<int>& nums, int k) {
        k = k % nums.size(); // Handle cases where k >= nums.size()
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
    
    void deleteElement(vector<int>& nums, int index) {
        if(index < 0) index = 0;
        nums.erase(nums.begin() + index);
    }

  public:
    int rotateDelete(vector<int> &arr) {
        int delPos = arr.size() - 1;
        while(arr.size() != 1) {
            rotateArray(arr, 1);
            deleteElement(arr, delPos);
            delPos -= 2;
        }
        return arr[0];
    }
};


// T.C. - O(n), S.C. - O(1)

class Solution {
public:
    int rotateDelete(vector<int> &arr) {
        int n = arr.size() - 1;
        int count = 1;
        int k = arr.size() / 2;

        while (k > 1) {
            if (arr[n] > 0) arr[n] = -1;
            if (arr[n - count] > 0) arr[n - count] = -1;

            while (n >= 0 && arr[n] < 0) {
                n--;
            }
            k--;
            count++;
        }
        return arr[n];
    }
};


// T.C. - O(1), S.C. - O(1)

class Solution {
public:
    int rotateDelete(vector<int> &arr) {
        int n = arr.size();
        int temp = n/2;
        int i = 3*(temp/2);
        
        if(temp%2) i++;
        

        return arr[n-i];
    }
};
