class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix[0].size();
        int answer=0;

        int high = matrix[n-1][n-1];
        int low = matrix[0][0];

        int mid = low + (high-low)/2;
        while(low<high){
            int count = 0;

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]<=mid){
                        count++;
                    }
                }
            }
            if(count < k){ 
                low = mid + 1;
            }
            else{
                high = mid;
            }
            mid = low + (high-low)/2;
        }
        return low;
    }
};