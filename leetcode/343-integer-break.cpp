1class Solution {
2public:
3    int integerBreak(int n) {
4        vector<int> dp(max(n+1,7));
5        dp[1]=0;
6        dp[2]=1;
7        dp[3]=2;
8        dp[4]=4;
9        dp[5]=6;
10        dp[6]=9;
11        for(int i=7;i<=n;i++){
12            dp[i]=dp[i-3]*3;
13        }
14        return dp[n];
15    }
16};