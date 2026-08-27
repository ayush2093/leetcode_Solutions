class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;
        for(int c:nums1){
            freq[c]++;
        }
        vector<int>ans;
        for(int i=0;i<nums2.size();i++){
            if(freq.find(nums2[i])!=freq.end()){
                ans.push_back(nums2[i]);
            }
        }
        unordered_map<int,int>fre;
        for(int c:ans){
            fre[c]++;
        }
        vector<int>ans1;
        for(auto c: fre){
            ans1.push_back(c.first);
        }
        return ans1;
    }
};