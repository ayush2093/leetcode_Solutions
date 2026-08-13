class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1)return nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])count++;
            if(nums[i]!=nums[i-1])count=1;
            if(count>nums.size()/2)return nums[i];
        }
        return 0;
    }
};