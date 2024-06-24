class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        //if n is 4, (matrix only depends on n)
        //2--1 time
        //3--2 times
        //4--3 times
        //5--4 times   // Exactly "n+1" is repeating for n times
        //6--3 times   // so if we find absolute difference between "n+1" and "q",and subtract it from "n",
        //7--2 times    // we will get frequency of "q"
        //8--1 time
        
        long long ans=n-abs(q-(n+1));
        return ans > 0 ? ans : 0;
    }
};
