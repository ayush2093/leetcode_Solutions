class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(int c: nums){
            freq[c]++;
        }
        int p=1;
        while(true){
            int mul=k*p;
            if(freq.find(mul)==freq.end()){
                return mul;
            }
            p++;
        }
        return 0;
    }
};