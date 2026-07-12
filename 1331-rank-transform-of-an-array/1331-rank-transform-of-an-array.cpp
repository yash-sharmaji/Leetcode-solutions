class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<pair<int,int>>vec(n);
        vector<int>answer(n);
        
        for(int i=0;i<n;i++){
            vec[i]={arr[i],i};
        }

        sort(vec.begin(),vec.end());

        int rank = 1;
        for(int i=0;i<n;i++){
            if(i<n-1 && vec[i].first==vec[i+1].first){
                answer[vec[i].second] = (rank);    
            }
            else{
                answer[vec[i].second]=(rank);
                rank++;
            }
            
        }
        return answer;
    }
};