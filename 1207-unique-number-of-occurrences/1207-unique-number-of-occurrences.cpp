class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(auto c:nums){
            freq[c]++;
        }
        unordered_map<int,int>ans;
        for(auto c:freq){
            ans[c.second]++;
        }
        for(auto c:ans){
            if(c.second>1){
                return false;
            }
        }
        return true;
    }
};