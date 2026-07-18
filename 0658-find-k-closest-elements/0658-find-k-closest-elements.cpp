class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int>answer(k);
        
        int index = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        if(index==n){
            index=n-1;
        }
        else if(index!=0 && x-arr[index-1] < arr[index]-x){
            index--;
        }

        if(index==0){
            for(int i=0;i<k;i++){
                answer[i]=arr[i];
            }
        }
        else{
            int low = max(0,index-k);
            int high = low+k-1;

            bool found=false;
            while(!found){
                if(high+1 < arr.size() && (abs(arr[high+1]-x)<abs(x-arr[low]))){
                    high++;
                    low++;
                }
                else{
                    found=true;
                }
            }

            for(int i=low,j=0;i<=high;j++,i++){
                answer[j]=arr[i];
            }
        }
        return answer;
        

    }
};