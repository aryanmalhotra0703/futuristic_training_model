class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int a=n;
        while(a>0){
            int digit=a%10;
            sum+=digit;
            product*=digit;
            a=a/10;
        }
        int c=sum+product;
        if(n%c==0){
            return true;
        }
        return false;
    }
};