class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n!=101){
            int product=1;
            int i=n;
            while(i!=0){
                int rem = i%10;
                product=product*rem;
                i=i/10;
            }
        if(product%t==0){
            return n;
        }
        n++;
    } 
    return -1;
    }
};