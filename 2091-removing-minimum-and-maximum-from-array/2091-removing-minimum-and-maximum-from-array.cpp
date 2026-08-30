class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minval=INT_MAX;
        int maxval=INT_MIN;
        int minindex=0;
        int maxindex=0;
        if(n==1){
            return 1;
        }

        for(int i=0;i<n;i++){
            if(maxval<nums[i]){
                maxval=nums[i];
                maxindex=i;
            }
        }
        for(int i=0;i<n;i++){
            if(minval>nums[i]){
                minval=nums[i];
                minindex=i;
            }
        }
        int left=max(minindex, maxindex)+1;
        int right=n-min(minindex,maxindex);
        int both = min(minindex, maxindex)+1+(n-max(minindex, maxindex));
        return min({left,right,both});
    }
};