class Solution {
private:
    double power(double x, int n){
         // check if power is 0 then give 1
        if(n == 0){
            return 1;
        }
        // tell recursion to solve further
        return x * power(x,n-1);
    }
public:
    double myPow(double x, int n) {
       if(n == INT_MAX){
           return (x == 1) ? 1 : (x == -1) ? -1 : 0;
       }
       if(n == INT_MIN){
           return (x == 1 || x == -1) ? 1 : 0;
       }

       double num = 1;
       if(n >= 0){
           num = power(x,n);
       }
       else{
           n = -n;
           num = power(x,n);
           num = 1.0/num;
       }
       return num;
    }
};
