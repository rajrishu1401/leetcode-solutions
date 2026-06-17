1class Solution {
2public:
3    vector<int> dp;
4    int tribonacci(int n) {
5        if(n==0){
6            return 0;
7        }
8        if(n<3){
9            return 1;
10        }
11        dp.resize(n+1,-1);
12        dp[0]=0;
13        dp[1]=1;
14        dp[2]=1;
15        return hlp(n);
16    }
17
18    int hlp(int n){
19        if(dp[n]!=-1){
20            return dp[n];
21        }
22        dp[n]=hlp(n-1)+hlp(n-2)+hlp(n-3);
23        return dp[n];
24    }
25};