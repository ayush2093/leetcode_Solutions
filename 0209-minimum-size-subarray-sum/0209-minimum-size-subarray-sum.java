class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n=nums.length;
        int minlen=Integer.MAX_VALUE,sum=0;
        int low=0;
        for(int high=0;high<n;high++){
            sum+=nums[high];
            while(sum>=target){
            minlen=Math.min(minlen,high-low+1);
            sum-=nums[low];
            low++;
            }
        }
        return minlen==Integer.MAX_VALUE ? 0:minlen;
    }
}