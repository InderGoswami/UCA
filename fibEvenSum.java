class Solution{
    static long evenFibSum(long N){
        // code here
        long a=0;
        long b=1;
        long c=0;
        long sum=0;
        while(c<N){
             if(c%2==0){
                sum+=c;
            }
            c=a+b;
            a=b;
            b=c;
        }
        return sum;
    } 
};
