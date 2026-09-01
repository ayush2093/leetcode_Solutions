class Solution {
public:
    int maximum69Number (int num) {
        vector<int>ans;
        int n=num;
        while(n>0){
            int rem=n%10;
            ans.push_back(rem);
            n=n/10;
        }

        int high=ans.size()-1,low=0;
        while(low<=high){
            swap(ans[high],ans[low]);
            low++;
            high--;
        }
        int m=0;
        int ans1=num;
        while(m<ans.size()){
            if(ans[m]==6){
            ans[m]=9;
            int product=0;
            for(int i=0;i<ans.size();i++){
                product=product*10+ans[i];
            }
            ans1=max(product,ans1);
            ans[m]=6;
            }
            m++;
        }
        return ans1;
    }
};