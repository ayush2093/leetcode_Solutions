class Solution {
    public boolean checkDivisibility(int n) {

        int sum=0;
        int product=1;
        int g=n;
        while(g!=0){
            int rem=g%10;
            sum+=rem;
            product*=rem;
            g/=10;
        }
        int ans=sum+product;
        return n%ans==0? true:false;
    }
}