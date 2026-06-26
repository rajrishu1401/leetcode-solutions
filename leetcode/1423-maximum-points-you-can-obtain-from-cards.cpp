1class Solution {
2public:
3    int maxScore(vector<int>& cardPoints, int k) {
4        
5        int n=cardPoints.size();
6        vector<int> pre(n+1);
7        for(int i=1;i<=n;i++){
8            pre[i]=pre[i-1]+cardPoints[i-1];
9        }
10        if(k>=n) return pre[n];
11        int li=1;
12        int lj=k;
13        int ri=n-k+1;
14        int rj=n;
15        int ans=0;
16        while(k){
17            int u=pre[lj]-pre[li-1];
18            int v=pre[rj]-pre[ri-1];
19            if(u>v){
20                ans+=cardPoints[li-1];
21                li++;
22                ri++;
23            }else{
24                ans+=cardPoints[rj-1];
25                rj--;
26                lj--;
27            }
28            k--;
29        }
30        return ans;
31    }
32};