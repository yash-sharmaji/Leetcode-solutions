class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int base = 0;
        for (char c : s)
            if (c == '1') base++;

        string t = "1" + s + "1";
        int n = t.size();

        int ans = base;
        int i = 1;

        while (i < n - 1) {
            if (t[i] != '0') {
                i++;
                continue;
            }
            int j = i;
            while (j<n && t[j]=='0'){
                j++;
            }
            int leftZero=j-i;

            if (j>=n||t[j]!='1') {
                i=j;
                continue;
            }
            int k=j;
            while(k<n && t[k]=='1'){
                k++;
            }
            int oneLen=k-j;

            if (k>=n || t[k]!='0') {
                i=k;
                continue;
            }
            int l=k;
            while(l<n && t[l]=='0'){
                l++;
            }
            int rightZero =l-k;

            if (j>0 && k<n)
                ans = max(ans,base-oneLen+leftZero+oneLen+rightZero);
            i=k;
        }
        return ans;
    }
};