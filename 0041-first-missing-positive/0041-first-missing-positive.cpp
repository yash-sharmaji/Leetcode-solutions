class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        
        while(i < n){
            if(nums[i]>0 && nums[i]<=n && nums[i]!=nums[i]-1 && nums[i]!=nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
            else{
                i++;
            }
        }
        int answer = n+1 ;
        for(int i =0 ;i<n;i++){
            if(nums[i]!=i+1){
                answer = i+1;
                break;
        }
            }
        if(nums.size()==1 && answer==0){
            return 2;
        }
        return answer;
    }
};