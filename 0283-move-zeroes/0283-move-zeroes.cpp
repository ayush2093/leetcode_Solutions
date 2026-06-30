class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        vector<int> arr(n);
        for(int i=0 ;i<n ;i++){
            if(nums[i]==0){
                count++;
            }
        }
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                arr[j]=nums[i];
                j++;
            }
        }
        
        nums=arr;
            }
};