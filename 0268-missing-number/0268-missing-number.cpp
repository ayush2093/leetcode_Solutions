class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size()-1;
        for(int i=0;i<nums[n];i++){
            if(nums[i]!=i){
                return i;
            }
        }
        if(nums[n]==n)
        return nums[n]+1;

        return -1;
    }
};