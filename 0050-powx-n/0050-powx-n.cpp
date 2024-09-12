class Solution {
public:

    double pow(double x, int n)
    {
        if(n==0)
        return 1;
        if(n==1)
        return x;

        double ans = double(pow(x,n/2));
        if(n%2 == 0)
        {
            double ans2 = double(ans*ans);
            return ans2;
        } 
        else
        {
            double ans2 = double(x*ans*ans);
            return ans2;
        }
    }
    double myPow(double x, int n) {
        double ans1 = pow(x,n);
        if(n<0)
        ans1 = 1/ans1;
        return ans1;
    }
};