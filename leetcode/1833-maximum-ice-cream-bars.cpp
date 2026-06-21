1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        int m=0;
5        for(int i:costs){
6            m=max(m,i);
7        }
8        vector<int> c(m+1);
9        for(int i:costs){
10            c[i]++;
11        }
12        int ans=0;
13        for(int i=1;i<c.size();i++){
14            if(coins<i){
15                return ans;
16            }
17            int u=min(c[i],coins/i);
18            coins-=(u*i);
19            ans+=u;
20        }
21        return ans;
22    }
23};