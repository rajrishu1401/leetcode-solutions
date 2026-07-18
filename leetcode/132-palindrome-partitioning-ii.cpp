1class Solution {
2public:
3    int minCut(string s) {
4        vector<vector<int>> dp(s.size());
5        vector<int> dp2(s.size(),-1);
6        for(int i=0;i<s.size();i++){
7            isPal(s,i,i,dp);
8            isPal(s,i,i+1,dp);
9        }
10        return hlp(dp,dp2,0)-1;
11    }
12    
13    int hlp(vector<vector<int>>& dp,vector<int>& dp2,int i){
14        if(i>=dp.size()){
15            return 0;
16        }
17        if(dp2[i]!=-1){
18            return dp2[i];
19        }
20        int m=INT_MAX;
21        for(int j:dp[i]){
22            m=min(hlp(dp,dp2,j+1),m);
23        }
24        dp2[i]=m+1;
25        return m+1;
26    }
27    void isPal(string& s, int i,int j,vector<vector<int>>& dp){
28        while(i>=0&&j<s.size()){
29            if(s[i]==s[j]){
30                dp[i].push_back(j);
31            }else{
32                return;
33            }
34            i--;
35            j++;
36        }
37    }
38};