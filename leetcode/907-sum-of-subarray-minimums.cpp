1class Solution {
2public:
3    int mod=1e9+7;
4    int sumSubarrayMins(vector<int>& arr) {
5        arr.push_back(0);
6        stack<pair<int,int>> s;
7        long long ans=0;
8        for(int i:arr){
9            int u=1;
10            while(!s.empty()&&s.top().first>=i){
11                ans+=((long long)s.top().second*(long long)u*s.top().first);
12                u+=s.top().second;
13                ans%=mod;
14                s.pop();
15            }
16            s.push({i,u});
17        }
18        return ans;
19    }
20};