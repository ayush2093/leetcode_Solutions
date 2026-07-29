class Solution {
public:
    const long long LIMIT = 1000001;

    // Computes nCr, capped at LIMIT
    long long comb(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res > LIMIT) return LIMIT;
        }
        return min(res, LIMIT);
    }

    // Counts distinct permutations of remaining letters
    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long long ways = 1;
        int rem = total;

        for (int x : cnt) {
            if (x == 0) continue;
            ways *= comb(rem, x);
            if (ways > LIMIT) return LIMIT;
            rem -= x;
        }

        return min(ways, LIMIT);
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string mid = "";
        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2)
                mid += char(i + 'a');
            half[i] = freq[i] / 2;
        }

        if (countWays(half) < k)
            return "";

        string left = "";
        int len = s.size() / 2;

        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left += char(c + 'a');
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};