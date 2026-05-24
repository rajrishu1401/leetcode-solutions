1class Solution {
2public:
3    int maxJumps(vector<int>& arr, int d) {
4        vector<int> dp(arr.size(),0);
5        int ans=0;
6        for(int i=0;i<arr.size();i++){
7            if(dp[i]==0){
8                ans=max(ans,hlp(arr,d,i,dp));
9            }
10        }
11        return ans;
12    }
13    int hlp(vector<int>& arr,int d,int i, vector<int>& dp){
14        //cout<<i<<"  f"<<endl;
15        int s=max(0,i-d);
16        int e=min((int)(arr.size()-1),(i+d));
17        int ans=0;
18        for(int u=i+1;u<=e;u++){
19            if(arr[u]>=arr[i]){
20                break;
21            }
22            if(dp[u]==0){
23                ans=max(ans,hlp(arr,d,u,dp));
24            }else{
25                ans=max(ans,dp[u]);
26            }
27        }
28        for(int u=i-1;u>=s;u--){
29            if(arr[u]>=arr[i]){
30                break;
31            }
32            if(dp[u]==0){
33                ans=max(ans,hlp(arr,d,u,dp));
34            }else{
35                ans=max(ans,dp[u]);
36                //cout<<i<<" s: "<<ans<<"  -> "<<dp[s]<<endl;
37            }
38        }
39        dp[i]=ans+1;
40        //cout<<i<<"  l: "<<dp[i]<<endl;
41        return ans+1;
42    }
43};