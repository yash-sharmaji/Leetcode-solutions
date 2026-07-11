class Solution {
public:
    int jump(vector<int>& vec) {

        int n = vec.size();

        if(n==1){
            return 0;
        }

        int jump=0;
        int currentEnd = 0;
        int maximumIndex = vec[0];
        if(vec[0] == vec.size()-1){
            return 1;
        }

        for(int i=0;i<n-1;i++){
            if( maximumIndex < vec[i] + i ){
                maximumIndex = vec[i] + i;
            }

            if(currentEnd == i){
                jump++;
                currentEnd = maximumIndex;
            }
        }
        return jump;
    }
};