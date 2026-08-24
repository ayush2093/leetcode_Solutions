class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int low = 0;
        unordered_set<int> window;
        for (int high = 0; high < nums.size(); high++) {
            if (window.find(nums[high]) != window.end()) {
                return true;
            }
            window.insert(nums[high]);
            if (high - low >= k) {
                window.erase(nums[low]);
                low++;
            }
        }
        return false;
    }
};