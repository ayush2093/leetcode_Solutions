class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> mp;
        for (int x : nums)
            mp[x]++;

        vector<int> freq;
        for (auto &p : mp)
            freq.push_back(p.second);

        int m = quantity.size();
        int full = 1 << m;

        vector<int> need(full, 0);

        for (int mask = 1; mask < full; mask++) {
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i))
                    need[mask] += quantity[i];
            }
        }

        int n = freq.size();

        vector<vector<int>> dp(n + 1, vector<int>(full, 0));
        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int mask = 0; mask < full; mask++) {
                if (!dp[i][mask])
                    continue;

                dp[i + 1][mask] = 1;

                int remain = (full - 1) ^ mask;

                for (int sub = remain; sub; sub = (sub - 1) & remain) {
                    if (need[sub] <= freq[i])
                        dp[i + 1][mask | sub] = 1;
                }
            }
        }

        return dp[n][full - 1];
    }
};