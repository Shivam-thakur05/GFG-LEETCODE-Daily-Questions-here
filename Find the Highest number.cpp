//sorting approach T.C. =  O(n logn), S.C. = O(1)

class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        sort(a.begin(),a.end());
        return a[a.size()-1];.
    }
};

//iterating approach T.C. =  O(n), S.C. = O(1)

class Solution {
public:
        int findPeakElement(vector<int>& a) {   
        int maxi = INT_MIN; 
        for(int i = 0; i < a.size(); i++){
            maxi = max(maxi,a[i]); }
        return maxi;
    }
    
};

//Binary approach T.C. =  O(logn), S.C. = O(1)

class Solution {
public:

    int findPeakElement(vector<int>& a) { 
        int n = a.size();
        int start = 0;
        int end = n-1;
        int mid = start + (end - start)/2;
        //int ans = a[0];
        
        while(start < end){
            if(a[mid]<a[mid+1]){
                start = mid+1;
            }
            else{
                end = mid;
            }
            mid = start + (end - start)/2;
        }
        return a[end];
    }
};
