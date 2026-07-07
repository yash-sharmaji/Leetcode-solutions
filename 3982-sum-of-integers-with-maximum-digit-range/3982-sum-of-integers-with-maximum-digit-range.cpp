class Solution {
public:
    int maxDigitRange(vector<int>& nums) {

        vector<int>copy(nums.size());
        for(int i=0;i<nums.size();i++){
            copy[i]=nums[i];
        }
        long long answer=0;
        
        int maxi_dg = INT_MIN;
        for(int i=0;i<nums.size();i++){
            
            int maxi = INT_MIN;
            int mini = INT_MAX;

            while(nums[i]!=0){
                if(maxi<(nums[i]%10)){
                    maxi=nums[i]%10;
                    
                }
                if(mini>(nums[i]%10)){
                    mini=nums[i]%10;
                }
                nums[i]/=10;
                
            }
            
            
            if(maxi-mini>maxi_dg){
                answer=copy[i];
                maxi_dg=maxi-mini;
            }
            else if(maxi-mini==maxi_dg){
                answer+=copy[i];
            }

        }
        return answer;
    }
};