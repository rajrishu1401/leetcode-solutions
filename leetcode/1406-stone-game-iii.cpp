1class Solution {
2public:
3    string stoneGameIII(vector<int>& stoneValue) {
4        vector<int> dp(stoneValue.size(),-1);
5        int a=hlp(stoneValue,0,dp);
6        if(a>0){
7            return "Alice";
8        }else if(a==0){
9            return "Tie";
10        }
11        return "Bob";
12    }
13    int hlp(vector<int>& stoneValue,int i,vector<int>& dp){
14        if(i>=stoneValue.size()){
15            return 0;
16        }
17        if(dp[i]!=-1){
18            return dp[i];
19        }
20        int u=stoneValue[i]-hlp(stoneValue,i+1,dp);
21        if((i+1)<stoneValue.size()){
22            int y=(stoneValue[i]+stoneValue[i+1])-hlp(stoneValue,i+2,dp);
23            u=max(u,y);
24        }
25        if((i+2)<stoneValue.size()){
26            int y=(stoneValue[i]+stoneValue[i+1]+stoneValue[i+2])-hlp(stoneValue,i+3,dp);
27            u=max(u,y);
28        }
29        dp[i]=u;
30        return u;
31    }
32};