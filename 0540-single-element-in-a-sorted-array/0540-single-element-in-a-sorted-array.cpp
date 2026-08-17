class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int start=0,end=n-1;
        if(n==1)return nums[0];
        while(start<=end){
            int mid = start+(end-start)/2;
            if(mid==0 && nums[0]!=nums[1])return nums[0];
            if(mid==n-1 && nums[n-1]!=nums[n-2])return nums[n-1];
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])return nums[mid];
            if(mid%2==0){//rest elements are even
                if(nums[mid]==nums[mid-1]){//single element in left
                    end=mid-1;
                }
                else{//single element in right
                    start=mid+1;
                }
            }
            else{//rest elements are odd
                if(nums[mid-1]==nums[mid]){//single element in right
                        start=mid+1;
                }
                else{//single element in left
                        end=mid-1;
                }
            }
        }
        return -1;
    }
};