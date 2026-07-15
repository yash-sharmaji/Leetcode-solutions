class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int answer = 0;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int high = n-1;
                int low = j+1;

                while(low<=high){
                    int mid = low + (high-low)/2;
                if (nums[mid] < nums[i] + nums[j])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
                answer = answer + high - j;
            }
        }
        return answer;
    }
};