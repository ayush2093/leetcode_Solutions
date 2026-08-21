class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int low = 1;
        int high = 0;

        // Find maximum element
        for (int num : nums) {
            high = Math.max(high, num);
        }

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Calculate sum of ceil(nums[i] / mid)
            int sum = 0;
            for (int num : nums) {
                sum += (num + mid - 1) / mid;
            }

            if (sum <= threshold) {
                // mid is a possible answer
                ans = mid;
                high = mid - 1;  // Try smaller divisor
            } else {
                // Divisor is too small
                low = mid + 1;
            }
        }

        return ans;
    }
}