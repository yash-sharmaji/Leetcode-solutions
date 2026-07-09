class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        int low = 0;
        int high = n-1;
        int mid = low + (high-low)/2;

        while(low <= high){
            if(citations[mid] < n- mid){
                low=mid+1;
            }
            else if(citations[mid] >= n - mid){
                high=mid-1;
            }
            mid=low + (high-low)/2;
        }
        return n-low;
    }
};