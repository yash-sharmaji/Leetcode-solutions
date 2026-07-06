class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]){
        return a[1] > b[1];
    }   
    return a[0] < b[0];       
}

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n= intervals.size();
        sort(intervals.begin(),intervals.end(),compare);

        int count = 0;
        for(int i=0;i<n-1;i++){
            if((intervals[i][0] <= intervals[i+1][0]) && (intervals[i][1] >= intervals[i+1][1])){
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = intervals[i][1];
                count++;
            }
        }        
        return n-count;
    }
};