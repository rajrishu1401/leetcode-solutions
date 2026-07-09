1class Solution {
2public:
3    int change(int amount, vector<int>& coins) {
4        vector<vector<unsigned long long>> dp(amount+1,vector<unsigned long long>(coins.size(),0));
5        for(int i=0;i<coins.size();i++){
6            dp[0][i]=1;
7        }
8        for(int i=1;i<=amount;i++){
9            if(i>=coins[0])dp[i][0]=dp[i-coins[0]][0];
10            for(int j=1;j<coins.size();j++){
11                dp[i][j]=dp[i][j-1];
12                //if(dp[i][j]>INT_MAX) break;
13                if(i>=coins[j])dp[i][j]+=dp[i-coins[j]][j];
14            }
15        }
16        return dp[amount][coins.size()-1];
17    }
18};