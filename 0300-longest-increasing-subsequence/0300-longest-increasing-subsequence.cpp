class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>vec;
        for(int i=0;i<n;i++){
            auto it = lower_bound(vec.begin(),vec.end(),nums[i]);

            if(it == vec.end()){
                vec.push_back(nums[i]);
            }
            else{
                *it = nums[i];
            }
        }
        return vec.size();
    }

};