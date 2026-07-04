1class DJS{
2public:
3    vector<pair<int,int>> rank;
4    vector<int> parent;
5    DJS(int n){
6        rank.resize(n+1,{0,INT_MAX});
7        for(int i=0;i<=n;i++){
8            parent.push_back(i);
9        }
10    }
11    int par(int a){
12        if(parent[a]==a){
13            return a;
14        }
15        return parent[a]=par(parent[a]);
16    }
17    void join(int a , int b , int c){
18        int ua=par(a);
19        int ub=par(b);
20        if(ua==ub){
21            rank[ua].second=min(rank[ua].second,c);
22            return;
23        }
24        if(rank[ua].first>rank[ub].first){
25            parent[ub]=ua;
26            rank[ua].second=min({rank[ua].second,c,rank[ub].second});
27        }else if(rank[ua].first<rank[ub].first){
28            parent[ua]=ub;
29            rank[ub].second=min({rank[ub].second,c,rank[ua].second});
30        }else{
31            parent[ua]=ub;
32            rank[ub].second=min({rank[ub].second,c,rank[ua].second});
33            rank[ub].first++;
34        }
35    }
36};
37class Solution {
38public:
39    int minScore(int n, vector<vector<int>>& roads) {
40        DJS d(n);
41        for(vector<int> i:roads){
42            d.join(i[0],i[1],i[2]);
43        }
44
45        return d.rank[d.par(1)].second;
46    }
47};