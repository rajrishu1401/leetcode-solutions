1class Solution {
2public:
3    int coinChange(vector<int>& coins, int amount) {
4        vector<int> dp(amount+1);
5        dp[0]=0;
6        for(int i=1;i<=amount;i++){
7            int u=INT_MAX;
8            for(int j:coins){
9                if(i>=j)
10                u=min(u,dp[i-j]);
11            }
12            dp[i]=u;
13            if(u!=INT_MAX) dp[i]++;
14        }
15        return dp[amount]==INT_MAX?-1:dp[amount];
16    }
17    
18};