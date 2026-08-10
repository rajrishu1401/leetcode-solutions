1class Solution {
2public:
3    bool winnerSquareGame(int n) {
4        vector<int> dp(n+1,-1);
5        return hlp(n,dp);
6    }
7
8    int hlp(int n,vector<int>& dp){
9        if(n==0){
10            return 0;
11        }
12        if(dp[n]!=-1){
13            return dp[n];
14        }
15        for(int i=1;(i*i)<=n;i++){
16            int y=hlp(n-(i*i),dp);
17            if(y==0){
18                dp[n]=1;
19                return 1;
20            }
21        }
22        return 0;
23    }
24};