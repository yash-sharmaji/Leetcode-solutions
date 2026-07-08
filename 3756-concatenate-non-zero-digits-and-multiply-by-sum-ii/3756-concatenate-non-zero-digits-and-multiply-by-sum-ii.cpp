class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;

        int n = s.size();

        vector<int> cnt(n + 1, 0);
        vector<long long> prefSum(n + 1, 0);

        vector<int> digits;

        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            prefSum[i + 1] = prefSum[i];

            if (s[i] != '0') {
                cnt[i + 1]++;
                prefSum[i + 1] += s[i] - '0';
                digits.push_back(s[i] - '0');
            }
        }

        int k = digits.size();

        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> H(k + 1, 0);
        for (int i = 0; i < k; i++)
            H[i + 1] = (H[i] * 10 + digits[i]) % MOD;

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = cnt[l];
            int R = cnt[r + 1] - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[r + 1] - prefSum[l];

            int len = R - L + 1;

            long long x = (H[R + 1] - H[L] * pow10[len]) % MOD;
            x = (x + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};