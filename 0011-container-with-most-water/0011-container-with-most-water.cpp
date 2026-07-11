class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int answer = min(height[0],height[n-1])*(n-1);
        for(int i = 0, j=n-1;i<j;){
            if(height[i]>=height[j]){
                j--;
            }
            else{
                i++;
            }
            answer = max(min(height[i],height[j])*(j-i),answer);
        }
        return answer;
    }
};