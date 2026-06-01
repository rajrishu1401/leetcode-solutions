1class Solution {
2public:
3    int minimumCost(vector<int>& cost) {
4        int ans=0;
5        sort(cost.begin(),cost.end(),greater<>());
6        int u=0;
7        for(int i:cost){
8            if(u==2){
9                u=0;
10                continue;
11            }
12            u++;
13            ans+=i;
14        }
15        return ans;
16    }
17};