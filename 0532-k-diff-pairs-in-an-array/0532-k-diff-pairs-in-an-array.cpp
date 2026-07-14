class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());

        set<int> s(nums.begin(),nums.end());
        vector<int> arr(s.begin(),s.end());

        int answer=0;
        if(k==0){
            for(int i=0;i<n-1;){
                if(nums[i]==nums[i+1]){
                    answer++;
                    while(i<n-2 && nums[i+1]==nums[i]){
                        i++;
                    }
                    i++;
                }
                else{
                    i++;
                }
            }
            return answer;
        }

        for(int i=0;i<arr.size();i++){
            int high = arr.size()-1;
            int low = i+1;

            while(low<=high){
                int mid = low + (high - low)/2;
                if(arr[mid] > arr[i]+k){
                    high = mid-1;
                }
                else if(arr[mid] < arr[i]+k){
                    low = mid + 1;
                }
                else{
                    answer++;
                    break;
                }
            }
        }
        return answer;
    }
};