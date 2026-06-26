class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1 = LLONG_MIN;
        long long max2 = LLONG_MIN;
        long long max3 = LLONG_MIN;

        for (int x : nums) {
            if (x > max1) {
                max1 = x;
            }
        }

        for (int x : nums) {
            if (x > max2 && x < max1) {
                max2 = x;
            }
        }

        for (int x : nums) {
            if (x > max3 && x < max2) {
                max3 = x;
            }
        }

        if (max3 == LLONG_MIN)
            return max1;

        return max3;
    }
};