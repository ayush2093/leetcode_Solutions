class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negativeCount = 0;
        int minAbs = INT_MAX;

        for (auto &row : matrix) {
            for (int x : row) {
                if (x < 0) negativeCount++;
                sum += abs((long long)x);
                minAbs = min(minAbs, abs(x));
            }
        }

        if (negativeCount % 2 == 0)
            return sum;

        return sum - 2LL * minAbs;
    }
};