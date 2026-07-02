class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int ans1=0;
      int ans2=0;
      for(int i=0 ;i<nums.size();i++){
        for(int j=0;j<nums.size();j++){
            if(nums[i]+nums[j]==target && i!=j){
                ans1=i;
                ans2=j;
            }
        }
      } 
      return {ans1,ans2}; 
    }
};