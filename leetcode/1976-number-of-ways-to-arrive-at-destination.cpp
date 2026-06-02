1class Solution {
2public:
3    int mod=1e9+7;
4    int countPaths(int n, vector<vector<int>>& roads) {
5        vector<vector<pair<int,int>>> nodes(n);
6        for(int i=0;i<roads.size();i++){
7            nodes[roads[i][0]].push_back({roads[i][1],roads[i][2]});
8            nodes[roads[i][1]].push_back({roads[i][0],roads[i][2]});
9        }
10        vector<long long> d(n,LLONG_MAX);
11        d[0]=0;
12        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
13        q.push({0,0});
14        while(!q.empty()){
15            pair<long long,int> r=q.top();
16            q.pop();
17            for(pair<int,int> i:nodes[r.second]){
18                long long dt=r.first+i.second;
19                if(d[i.first]>dt){
20                    d[i.first]=dt;
21                    q.push({dt,i.first});
22                }
23            }
24        }
25        vector<long long> d1(n,0);
26        d1[0]=1;
27        q=priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> ();
28        vector<bool> v(n);
29        q.push({0,0});
30        while(!q.empty()){
31            pair<long long,int> r=q.top();
32            q.pop();
33            for(pair<int,int> i:nodes[r.second]){
34                long long dt=r.first+i.second;
35                if(d[i.first]==dt){
36                    d1[i.first]+=d1[r.second];
37                    d1[i.first]%=mod;
38                    if(!v[i.first]) {
39                        v[i.first]=true;
40                        q.push({dt,i.first});
41                    }
42                }
43            }
44        }
45        return d1[n-1];
46    }
47};