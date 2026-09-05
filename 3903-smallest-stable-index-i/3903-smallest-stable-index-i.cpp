class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        while(i<n){
        int largest=INT_MIN;
        int smallest=INT_MAX;
            for(int j=0;j<=i;j++){
                largest=max(largest,nums[j]);
            }
            for(int j=i;j<n;j++){
                smallest=min(smallest,nums[j]);
            }
            int hero=largest-smallest;
            if(hero<=k)return i;
            i++;
        }
        return -1;
    }
};