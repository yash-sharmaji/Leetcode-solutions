class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>answer;
        
        string s="123456789";
        
            for(int i=2;i<=9;i++){
                for(int j=0,k=i-1;k<9;j++,k++){
                    int number = stoi(s.substr(j,k-j+1));
                    if(number >=low && number<=high){
                        answer.push_back(number);
                    }
                    else if(number>high){
                        return answer;
                    }
                }
            }
        return answer;
    }
};