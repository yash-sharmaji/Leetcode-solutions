class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_1 = nums[0];
        int xor_2 = 0;
        for(int i=1;i<nums.size();i++){
            xor_1 = xor_1 ^ nums[i];
            xor_2 = xor_2 ^ i;
        }

        return xor_1 ^ xor_2 ^ nums.size();
    }
};