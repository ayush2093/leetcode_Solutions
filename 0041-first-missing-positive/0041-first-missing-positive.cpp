class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int ,int>freq;
        for(int c : nums){
            freq[c]++;
        }
        int n =nums.size()-1;
        if(nums[n]<1){
            return 1;
        }
        
        for(int i=1;i<nums[n];i++){
            if(freq.find(i)==freq.end()){
                return i;
            }
        }
        return nums[n]+1;  
    }
};