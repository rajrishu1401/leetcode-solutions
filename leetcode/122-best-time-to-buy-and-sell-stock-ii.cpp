1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int c=prices[0];
5        int ans=0;
6        for(int i=1;i<prices.size();i++){
7            if(prices[i]<=prices[i-1]){
8                ans+=(prices[i-1]-c);
9                c=prices[i];
10            }
11        }
12        ans+=prices[prices.size()-1]-c;
13        return ans;
14        
15    }
16};