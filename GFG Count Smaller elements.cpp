class Solution {
  private:
    int binarySearch(int key, vector<int>&temp){
        int index = -1;
        int low = 0,high = temp.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(temp[mid] == key){
                index = mid;
                high = mid - 1;
            }
            else if(temp[mid] > key) high = mid - 1;
            else low = mid + 1;
        }
        return index;
    }
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        vector<int>ans;
        vector<int>temp(arr.size());
        //store the value in temp array
        for(int i = 0; i < arr.size(); i++){
            temp[i] = arr[i];
        }
        //sort the temp array
        sort(temp.begin(),temp.end());
        
        //find the index of every element in arr
        for(int i = 0; i < arr.size(); i++){
            int idx = binarySearch(arr[i],temp);
            ans.push_back(idx);
            //after push the index in ans we have to erase that index
            temp.erase(temp.begin()+idx);
        }
        return ans;
    }
};
