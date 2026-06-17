1class Solution {
2public:
3    vector<int> dp; 
4    int minCostClimbingStairs(vector<int>& cost) {
5        dp.resize(cost.size(),-1);
6        return min(hlp(cost,0),hlp(cost,1));
7    }
8
9    int hlp(vector<int>& cost,int st){
10        if(st>=cost.size()){
11            return 0;
12        }
13        if(dp[st]!=-1){
14            return dp[st];
15        }
16        int u=hlp(cost,st+1);
17        u=min(u,hlp(cost,st+2));
18        dp[st]=u+cost[st];
19        return dp[st];
20    }
21
22
23};